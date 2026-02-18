# Expressions
Expressions are split into 2 categories:
- `avalue` - something that has a memory address.
- `lvalue` - something that can be assigned to. May not have a memory address.
- `rvalue` - everything else.

## Location
Location is a way to describe what an expression results in. It can be one of:
- memory address stored in a GRP register
- compile-time symbol
- register name
- rbp offset
- literal: signed 64-bit integer value
- literal: unsigned 64-bit integer value
- literal: 64-bit float value

In order to optimize the code a little bit, some expressions will not result in a
memory address being written to a register. For example, the address of a local
variable is just some offset relative to `rbp`.

Code that interacts with locations (accesses a value stored at a location, writes to
a location, etc) may be a little different depending on the type of location.

## `g()`
`g(e)` is used to generate code for expression `e`. It results in a location of the
expression. To access its value, `v(g(e))` is used. To access its address (or, to
write to it), `a(g(e))` is used.

## Some notations
- `R0`, `R1`, ... - GPR registers (unnamed)
- `S0`, `S1`, ... - SSE registers (unnamed)
- `L0`, `L1`, ... - locations.
- `<symbol>` - compile time symbol.
- `v(L)` - value stored at location `L`. May require additional instructions, for
  example, to fetch the data from memory.
- `a(L)` - address of location `L`. Used to write to this location. May require
  addition instructions.
- `L(reg: <name>)` - location, register alias.
- `L(symbol: rel <symbol>)` - location, symbol.
- `L(addr: <expr>)` - location, memory address.
- `L(val: <expr>)` - location, value.
- `L(local: rbp - <offset>)` - location, local variable stack offset.
- `L(ilit: <value>)` - location, signed integer literal.
- `L(ulit: <value>)` - location, unsigned integer literal.
- `L(flit: <value>)` - location, float literal.
- `res -> L0` - means that the expression result is stored at `L0`

Expressions are evaluated somewhat lazily. If an expression results in a value stored
in an SSE register, it is not immediatelly transfered to a GPR register. This is done
to optimize expressions like `a f+f (b f+f c)`. Thereby:
- `trans(L1) -> L2` transfer data from L1 into L2 if it is required. Think like
  transfering bits from XMM0 to RAX. This is just copying bytes, without any casting.

Operators almost always operate on operands of the same type. Even though you can do
something like `a d+f b`, the compiler will convert `a` to a float. So:
- `stronger(T,U)` - stronger of types `T` and `U`.
- `weaker(T,U)` - weaker of types `T` and `U`.
- `prom(L1, T, U) -> L2` - promotes data in `L1` of type `T` to type `U`, storing int
  in `L2`.
- `op(...)` - instructions implementing a specific operator.

Operands will usually be required to belong to at least some category. For example,
taking address of an expression requires that expression to be at least an `avalue`.
So this will be noted as:
`arg: avalue+` - means at least `avalue`

## List of expressions

### Local variable access
`name` where `name` is the name of the variable on the stack. Given that it has an
offset `offset`:

```asm
type: avalue

g:
    res -> L(local: rbp - <offset>)
```

### Register alias access
`name` where `name` is the name of the name of the variable that is an alias of
register `reg`.

```asm
type: lvalue

g:
    res -> L(reg: <reg>)
```
### Global symbol access
`name` where `name` is the name of a global symbol.

```asm
type: avalue

g:
    res -> L(symbol: rel <name>)
```

### Signed integer literal
`value` where `value` is a 64-bit signed integer literal.

```asm
type: rvalue

g:
    res -> L(ilit: <value>)
```

### Unsigned integer literal
`value` where `value` is a 64-bit unsigned integer literal.

```asm
type: rvalue

g:
    res -> L(ulit: <value>)
```

### Float literal
`value` where `value` is a 64-bit double precision float literal.

```asm
type: rvalue

g:
    res -> L(flit: <value>)
```

### Simple unary operators
These have the form of `op T arg0`.

```asm
type: rvalue
arg0: rvalue+

g:
    g(arg0) -> L0
    op(v(L0)) -> L1
    res -> L1
```

### Simple binary operators
These have the form of `arg0 T op U arg1`.

```asm
type: rvalue
arg0: rvalue+
arg1: rvalue+

g:
    g(arg0) -> L0
    prom(L0, T, stronger(T,U)) -> L1
    g(arg1) -> L2
    prom(L2, U, stronger(T,U)) -> L3
    op(v(L1), v(L3)) -> L4
    res -> L4
```

### Type cast
`arg0 T ? U`. Supported conversions: Any pair of `b,sb,w,sw,d,sd,q,sq,f,F`

```asm
type: rvalue
arg0: rvalue+

g:
    g(arg0) -> L0
    op(v(L0)) -> L1
    res -> L1
```

### Layout access
`arg0 Layout . field`.

```asm
type: avalue
arg0: avalue+

g:
    g(arg0) -> L0
    res -> L(val: a(L0) + <offset of field in Layout>)
```

### Address of
`[arg0] arg1`.

If `arg0` is present:
```asm
type: rvalue
arg0: rvalue+
arg1: avalue+

g:
    g(arg0) -> L0
    g(arg1) -> L1
    res -> L(val: v(L0) + a(L1))
```

If `arg0` is not present:
```asm
type: rvalue
arg1: avalue+

g:
    g(arg1) -> L1
    res -> L(val: a(L1))
```

### Pointer dereference
`arg0 [arg1]`

If `arg0` is present:
```asm
type: avalue
arg0: rvalue+
arg1: rvalue+

g:
    g(arg0) -> L0
    g(arg1) -> L1
    res -> L(addr: v(L0) + v(L1)
```

If `arg0` is not present:
```asm
type: avalue
arg0: rvalue+

g:
    g(arg0) -> L0
    res -> L(addr: v(L0))
```



# Statements
