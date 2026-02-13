# Introduction
This document is a brief introduction to bbb programing.
bbb is a low level programming language designed with assembly and C in mind. It
tries to stay in between the two: it has high level constructions like loops and
variable definitions, but also allows precise memory control and nasm blocks of
code. It is compatible with ABI64 x86-64 unix-like systems, meaning it can use the
standard C library without any issues.

bbb compiles into nasm code.

# Spirit of bbb
bbb is heavily inspired by assembly programming. One of the main features of bbb
is absence of data types, at least in the conventional meaning. Variables in bbb
do not have types - everything is just raw memory blocks. However, as it is with
assembly, working with data usually requires some interpretation of that data.
Therefore, operators in bbb do have types.

For example, defining a variable looks simple:
```
var: m8
```
This will allocate 8 bytes (hence m8) on the stack that will be accessible by
typing `var`. No type here. Just pure memory; you could as well do `var:
m10000`.

On the other hand, say we have `var: m8`, you can interpret that memory in
several ways:
1. `var f+= 1.0` - treats `var` (or rather its firsst 4 bytes) as a 4-byte float, and increments its value by `1.0`
2. `var sb+= 1` - treats `var` (or rather just its first byte) as a 1-byte signed integer, and increments its
   value by `1`

Another feature of bbb is deep compatibility with ABI64, giving the programmer
full control over what is happening. You can specify how exactly your memory has
to be passed to / returned from a function. More on this in the next sections.

bbb compiles to intel assembly, which later has to be compiled by nasm.
Therefore, inserting nasm blocks directly in the code is supported. Just type
your assembly inside of `%nasm %endnasm`, and it will be put in the output. This
nasm code can interact with bbb variables, so the programmer has full support
over everything happening in his program. For example

```asm
// inside of some function
syscall_num: m8
arg1: m8
arg2: m8
arg3: m8
res: m8
...
%nasm
    mov rax, qword %syscall_num
    mov rdi, qword %arg1
    mov rsi, qword %arg2
    mov rdx, qword %arg3
    syscall
    mov qword %res, rax
%endnasm
...
ret res
```

# Language guide
# Program structure
bbb program is very similar to C. You have global variables, functions, some
other declarations (in case of bbb - `extern` is the only declaration at the
moment). There are no macros yet - not sure if they will ever be added. Another
element of a program may be a top-level nasm block.

Global variables and function are by default global - meaning they are
accessible from other compilation units. This is implemented by adding `global
<symbol name>` to the assembly output directly above the symbol. However, in bbb
you can add `static` to the declaration of a symbol, and it will be local to the
compilation unit; the `global <symbol name>` will not be added in the assembly
output.

Global variables are always put in the `.bss` section. Functions are put in the
`.data` section. Nasm blocks are put directly into the output; you have to say
what section it is yourself.

The order in which objects are generated is really simple. Code for each element
is generated and put in the output in the same order that it appears in the
file: meaning that for a program that is made of several elements (V - global
variable declaration, F - function declaration, E - extern declaration, N - nasm
block) the following will be generated (g(X) means assembly that represents X):
```
V
F
F
E
N
F
V

becomes

section .bss
g(V)

section .text
g(F)

section .text
g(F)

g(E)

g(N)

section .text
g(F)

section .bss
g(V)
```

So basically, each function will go after `section .text`, and each
variable declaration will go after `section .bss`

## Global variables
Global variables are placed in the `.bss` section. You define a global variable
like this:
```asm
var: m8
```

This declares a 8-byte variable with the name `var` which will be declared
global in the assembly output. To make it static (and local to the current
compilation unit) add `static` after the colon:
```asm
var: static m8
```

`m8` is the length that the variable occupies. Remember, there are no types, so
everything is simple memory. You can declare variables of any length:
```asm
var1: m1                     // 1 byte
var2: m1000000               // 1 megabyte
var3: m(sizeof Layout)       // size of the layout, will be explained later
```

Additionally, you may align your variables to make their addresses divisible by
a certain number. Note that this is optional, and by default all variables have
the alignment of 8.
```asm
var1: m1 align1              // address of var1 will be divisible by 1
var2: m1 align100000         // address of var2 will be divisible by 1000000
var3: m1                     // address of var3 will be divisible by 8
```

## Extern declaration
If you want to use symbols (like functions and global variables) from other
compilation units, you need to declare those symbols as extern. For example, to
interface with `printf` from libc:
```asm
extern printf

...

call printf("hello world!\n");
```

Such extern declarations are simply copied to the output code, without any
modifications.

## Layouts
Layouts are similar to C structures, because both are just a collection of named
offsets. When you write `a.b` in C, you simple access memory at a certain offset
from `a`, which is where the field `b` is stored. Layouts function similarly,
but they are a little more 'raw'.

Another import thing to keep in mind is that using layouts is a way to view
memory differently. You can `apply` different layouts to memory; it will simple
use different offsets for your layouts. But let's start simple.

In a layout, every field may occupy some continuous memory. Simplest example:
```asm
vec2: layout {
    x: m4               // will be at offset 0
    y: m4               // will be at offset 4
}
```

Here, `vec2` is a collection of 2 offsets: `x` and `y`. How to use this layout?
Allocate a memory for it like this:
```asm
point: m(sizeof(vec2))
```

Now, you can access `x` and `y` parts by writing:
```asm
point vec2. x
point vec2. y
```

Note how you have to specify the layout name together with the dot operator.

We did not create a layout here. We simply said `"here's a 8-byte region of
memory, now treat is as if it was a vec2"`. We could, as well do this:

```asm
vec4: layout {
    a: m2              // will be at offset 0
    b: m2              // will be at offset 2
    c: m2              // will be at offset 4
    d: m2              // will be at offset 6
}

...

point vec4. a
point vec4. b
point vec4. c
point vec4. d
```

It would use the same memory we allocated for `point`. Again, layouts are simply
a way to look at memory and give it some structure in our minds. Writing `point
vec2. x` is the same as saying `"take point, now offset it by 0 bytes"`. Writing
`point vec4. c` is the same as saying `"take point, now offset it by 4 bytes"`.

Back to layouts. Each offset is defined by the offset behind it + how much that
previous offset takes. Unlike C structures, layouts do not introduce any
paddings, alignments, and other complicated things; you have to do everything by
hand by padding manually. To add a padding, use the nameless offset `_`:
```asm
i_take_10_bytes: layout {
    a: m4           // is at offset 0
    _: m2           // is at offset 4, but you cannot access it
    b: m4           // is at offset 6
```

By padding, you can successfully recreate any C structure if you know how it
is made. Well, no shortcuts here :)

Layouts do not have an alighment requirement, as it makes no sense; any region
can be viewed using the given layout.

For now, this is everything you need to know about layouts. More will be
explained in the section focusing on ABI calling conventions.

## Functions
You can declare functions in bbb; they will be put in the `.text` section.

A function is essentially an address that contains code which can be called using the
`call` instruction. Like in C, you can define a function that accepts some parameters
and returns at most one value. 
```asm
sum: fn(a, b) -> m8 {
    ret a + b
}
```

This is the simplest example of a function. The `-> m8` part means that it returns a
8-byte long value. This is optional, as the function may not return any value (like
`void` in C). Function parameters, just like everything else, default to 8-byte
values, so `a` and `b` here will be treated as `m8` unsigned integers.

### ABI calling conventions
ABI64 specifies the exact way functions have to work. When calling a function, the
stack has to be aligned to 16 bytes. Fuction parameters are split into 2 categories:
1. Short values: those which take at most 16 bytes of memory. Include C data types
   such as `char`, `int`, `float`, `struct` (whose length is at most 16 bytes).
2. Long values: those which take more than 16 bytes of memory. These include longer
   structures.

When passing arguments to a function, short ones first go into the registers: `RDI`,
`RSI`, `RDX`, `RCX`, `R8`, `R9`. Registers `XMM0 - XMM7` are also used to pass float
values. If there are no more registers to use, stack memory is used. If a long value
is passed, it is passed by reference by passing a pointer to it.

When returning a short value from a function, it will either go to `RAX`, `RAX:RDX`,
`RAX:XMM0`, or `XMM0:XMM1` depending on the type of value it is (this will be
explained just a bit later). Longer values are not really returned; if a longer value
is to be returned, a pointer to a space allocated for it will be passed to the
function as the first argument, before the first actuall argument.

Regarding whether a value goes to a general purpose register (`GPR`) or a `XMM` register. Each
chunk of 8 bytes is classified as one of the following:
1. `MEMORY` - goes on stack. Has the highest priority.
2. `INT` - integer value, goes to `GPR` (like `RAX`).
3. `SSE` - float value, goes to an `XMM` register.

If you pass a 4-byte integer, it is classified as `INT`. If you pass a `struct {int;
int;}` it has 8 bytes and is classified as 1 `INT` chunk. If you pass a `struct
{int; double;}` it is 16 bytes and is classified as 2 chunks: `INT` (first integer
and 4 bytes of padding which go to a `GPR`) and `SSE` (double, goes to a `XMM`). If
a chunk is made of values which have different classifications, the one with higher
priority defines the result classification: `struct {int; float;}` is 8 bytes long
and has 2 elements that form a chunk: `INT` and `SSE`. Therefore, it is classified as
`INT`, and will be passed to a `GPR`.

Since bbb does not have types, you have to manually define the classification of each
parameter, both when declaring and calling a function. Example:
```asm
sum: fn(a: m4 #int, b: m8 #sse) -> m8 #sse {
    return a d+F b      // operators will be covered later
                        // but this is just a sum of
                        // an int and a double value in C
}

extern sum2             // same as sum, but defined elsewhere

...

// bbb knows the signature of sum
// so we dont need to specify #int #sse #mem.
res = call sum(1, 5.23); // 6.23

// here it is unknown, so we
// specify it manually.
res = call m8 #sse sum2(1: m4 #int, 5.23: m8 #sse); // 6.23
```

Note that you cannot specify more than one chunk classification per argument. How do
we handle longer values? This is where layouts come to help. We can classify chunks
in the layout declaration:
```asm
// represents C struct {int; double;}
struct: layout #int #sse {
    int: m4
    _: m4
    double: m8
}

...

// say we have a function that accepts and returns
// `struct` we defined layer
extern foo

...

res: m(sizeof struct)

res = call #struct foo(res: m(sizeof struct) #struct)
```

Note the `#int #sse` part after the `layout` keyword. Here we describe each chuck,
stating that the first one is `int`, and the second one is `#sse`. If your structure
is small (like 8 bytes), you only specify one chunk. If your structure does not
contain floats, you don't need to specify anything at all; by default, everything is
classified as `int`.

### Back to functions
Should have mentioned that parameters and arguments are 8 bytes by default. You can
specify their size by adding `: m16` or any other size after the argument:
```
useless: fn(data: m1024) -> m1024 {
    ret data
}

...

res = useless(data)
```

Note that values bigger than 16 bytes are passed by reference.




