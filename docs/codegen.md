- [Expressions](#expressions)
- [Semantic analysis](#semantic-analysis)
- [Codegen](#codegen)
  - [Leaf expressions.](#leaf-expressions)
    - [`name`](#name)
    - [`literal`](#literal)
  - [About operator type conversions](#about-operator-type-conversions)
  - [About reinterpretation](#about-reinterpretation)
  - [Basic, trivial operators (rvalues)](#basic-trivial-operators-rvalues)
    - [Unary operators](#unary-operators)
    - [Binary operators](#binary-operators)
  - [Special operators](#special-operators)
    - [Unary operators](#unary-operators-1)
      - [Type cast (rvalue)](#type-cast-rvalue)
      - [Layout access (avalue)](#layout-access-avalue)
    - [Binary operators](#binary-operators-1)
      - [Address of (rvalue)](#address-of-rvalue)
      - [Pointer dereference (avalue)](#pointer-dereference-avalue)
      - [Assignment operator (lvalue)](#assignment-operator-lvalue)
  - [Function call](#function-call)

# Expressions
Expressions are split into 3 categories (types):
1. Addressable - these expressions have a memory address. Think of variables, array\
   elements, values pointed by pointers.
2. Assignable - these do not have a memory address, but can be assigned to. Think of\
   a register: you can make an alias and assign to it, but it makes no sense to\
request an address of a register.
3. Evaluatable - the rest of the expressions. These do not have an address, and\
   cannot be assigned to.

Codegen can be of 3 different variations as well.
1. Evaluating an expression. This calculates the value of the expression, putting its
   result in some register to use.
2. Calculating the address of an expression. This calculates the address of an
   expression, and puts its value in a GPR register.
3. Calculating the location of an expression. Sounds weird; it is almost the same as
   the previous item. However, for registers / local variables this will not put an
address into a register. The codegen will use the register / rbp offset directly.

Lets call:
- Addressable - `avalue`
- Assignable - `lvalue`
- Evaluatable - `rvalue`
- Evaluating an expression codegen - `g_eval`
- Calculating the address - `g_addr`
- Calculating the location - `g_loc`
- GPR registers - unnamed `R0` - `R15`
- SSE registers - unnamed `XR0` - `XR15`
- Constants calculated at compile time / other compile time things - `<...>`
- Arguments of operators - `arg0` - ...
- Interpret 8-byte val as T - `reint(val, T)`. Only if required.
- Convert between types - `conv(val, T, U)`. Only if required.
- GPR / SSE register - `S0` - `S15`
- Operator nasm code - `op(arg1, arg2, ...)`
- Transfer of RAW binary from S1 to S2 - `move(S1) -> S2`. Option / can be ommited if
  possible.
- Location (rbp - X, address, register alias) - `L0` ...
- Stronger / weaker between types - `weaker(T,U)` / `stronger(T,U)`

## Semantic analysis
This phase is required to determine the type of each expression
(avalue/lvalue/rvalue). Impossible combinations of language constructs will result in
a compilation error (like `[](a + b)`). Statements and other constructions, which are
not expressions, do not possess a type: it is relevant only in the context of
expressions.

After this phase, each expression will have a type pinned to it.

## Codegen
This is the second and last phase of the compilation.

### Leaf expressions.

#### `name`
This can be a local variable / register alias / global symbol

For local variable at offset `<offset>`: (avalue)
```asm
g_eval:
    mov R0, qword [rbp - <offset>]
g_addr:
    lea R0, qword [rbp - <offset>]
g_loc:
    ; rbp - <offset>
```

For register alias `RX`: (lvalue)
```asm
g_eval:
    ; uses RX directly
g_addr:
    not implemented
g_loc:
    ; RX
```

For global symbol `<symbol>`: (avalue)
```asm
g_eval:
    mov R0, qword [rel <symbol>]
g_addr:
    lea R0, qword [rel <symbol>]
g_loc:
    ; rel <symbol> or lea R0, [rel symbol] depending on the context
```

#### `literal`
Can be a 64-bit signed int, 64-bit unsigned int, 64-nit double float, and a string.
All of them are rvalues.

For 64-bit signed / unsigned ints:
```asm
g_eval:
    ; uses the value directly in its UNSIGNED 2 form.
```

For each unique double constant, a symbol is created in the `.rodata` section:
```asm
section .rodata
    <some symbol> dq <literal value>
g_eval:
    movsd XR0, [rel <some symbol>]
```

For string literals, the same is done as with doubles. Strings always end with null.

### About operator type conversions
Most of operators require their arguments to be cast to another type. If the operator
cannot natively do the operation (like adding an int to a float), the "weaker" type
has to be cast to the "stronger" type. The supported casts are:
- `b,w,d,q` -> `f,F`. Implemented using `cvtsi2ss` / `cvtsi2sd`.
- `ub,uw,ud,uq` -> `f,F`. Similar implementation, but special care is taken when
  addressing the sign.

### About reinterpretation
`reint(val ,T)` is used in case we need to load raw memory into XMM registers.

### Basic, trivial operators (rvalues)
All these operators emit a little different code for operands of different types.
However, the types always have to be the same AFTER CONVERSION.

#### Unary operators
For unary operators, codegen is rather simple. Almost all of unary operators are rvalues,
and for them:
```asm
rvalue arg0

g_eval:
    g_eval(arg0) -> S0
    reint(S0, T) -> S1
    op(S1) -> S2
```

The rest will be covered later.

#### Binary operators
For binary operators, codegen is simple too. Most of bunary operators are rvalues,
and for them (assuming `arg0 T op U arg1`):
```asm
rvalue arg0
rvalue arg1

g_eval:
    g_eval(arg0) -> S0
    reint(S0, T) -> S1
    conv(S1, weaker(T,U), stronger(T,U)) -> S2
    g_eval(arg1) -> S3
    reint(S3, U) -> S4
    conv(S4, weaker(T,U), stronger(T,U)) -> S5
    op(S2, S5) -> S6
```

Other binary operators will be covered later.

### Special operators

#### Unary operators

##### Type cast (rvalue)
Casts between different types, ALWAYS resulting in an `rvalue`.
Has form of `value T?U`, and produces an `rvalue` with the value from converting
`value` from type `T` into type `U`.

Supported conversions: Any pair of: `b,sb,w,sw,d,sd,q,sq,f,F`.

Implementation is not complicated but huge, so in general:
```asm
rvalue arg0

g_eval:
    g_eval(arg0) -> S0
    move(S0) -> S1 ; if a move is required, like S0 being RAX and S1 being XMM0
    ; code that converts from S1 of type T to S2 of type U
    move(S2) -> R0
```

##### Layout access (avalue)
`value layout. field` looks into the memory at the address of `value` offset by the
offset of `field` specified by `layout`.
```asm
avalue arg0

g_eval:
    g_loc(arg0) -> L0
    mov R0, qword [L0 + <offset of field>]
g_addr:
    g_loc(arg0) -> L0
    lea R0, [L0 + <offset of field>]
g_loc:
    ; same as g_addr
```

#### Binary operators

##### Address of (rvalue)
Address off may be considered a unary operator too (if it has no offset), but we will
put it here. To remind: `[offset]value` is equivalent to taking address of `value`,
and offsetting it by `offset`.

```asm
rvalue arg0: offset
avalue arg1: value

g_eval:
    g_eval(arg0) -> S0
    move(S0) -> R0
    g_loc(arg1) -> L0
    lea R1, [L0 + R0] ; part 'L0 + ' may be ommited if offset is zero.
```

##### Pointer dereference (avalue)
Same as with address off: this is a binary operator. `value[offset]` is equivalent to
looking in memory at the address of `value` offset by `offset`.

```asm
rvalue arg0: value
rvalue arg1: offset

g_eval:
    g_eval(arg0) -> S0
    move(S0) -> R0
    g_eval(arg1) -> S1
    move(S1) -> R1
    mov R2, qword [R0 + R1]
g_addr:
    g_eval(arg0) -> S0
    move(S0) -> R0
    g_eval(arg1) -> S1
    move(S1) -> R1
    lea R2, [R0 + R1]
g_loc:
    ; same as g_addr
```

##### Assignment operator (lvalue)
First of all, operators like `+=` will always be compiled as the pair of `+`, then
`=`.

Second, this operator is special as it can operate on memory blocks. However, the
length of the memory blocks have to be the same.

First, let's talk about version without memory blocks: `arg0 T=U arg1`
```asm
lvalue arg0
rvalue arg1

go_eval:
    g_loc(arg0) -> L0
    g_eval(arg1) -> S0
    reint(S0, U) -> S1
    op(L0, S1) -> S2; writes. takes into consideration types T and U
go_addr:
    ; doesnt have
go_loc:
    g_loc(arg0) -> L0
    g_eval(arg1) -> S0
    reint(S0, U) -> S1
    op(L0, S1) -> S2; writes. takes into consideration types T and U
    ; result is L0
```

### Function call
This shit is hard, will explain later.












