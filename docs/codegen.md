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
- Conversion between types - `conv(val, T1, T2)`. Only if required.
- GPR / SSE register - `S0` - `S15`
- Operator nasm code - `op(arg1, arg2, ...)`
- Transfer from S1 to S2 - `move(S1) -> S2`. Option / can be ommited if
  possible.
- Location (rbp - X, address, register alias) - `L0` ...

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

### Basic, trivial operators (rvalues)
All these operators emit a little different code for operands of different types.
However, the types always have to be the same AFTER CONVERSION.

#### Unary operators
For unary operators, codegen is rather simple. All of unary operators are rvalues,
and for them:
```asm
g_eval:
    g_eval(arg0) -> S0
    conv(S0, q, T) -> S1
    op(S1) -> S2
```

#### Binary operators
For binary operators, codegen is simple too. Most of bunary operators are rvalues,
and for them:
```asm
g_eval:
    g_eval(arg0) -> S0
    conv(S0, q, T) -> S1
    g_eval(arg1) -> S2
    conv(S2, q, T) -> S3
    op(S1, S3) -> S4
```

Other binary operators will be covered later.

### Special operators

#### Binary operators

##### Address of (rvalue)
Address off may be considered a unary operator too (if it has no offset), but we will
put it here. To remind: `[offset]value` is equivalent to taking address of `value`,
and offsetting it by `offset`.

```asm
arg0: offset
arg1: value

g_eval:
    g_eval(arg0) -> S0
    move(S0) -> R0
    g_loc(arg1) -> L0
    mov R1, qword [L0 + R0] // part 'L0 + ' may be ommited if offset is zero.
```

#####









