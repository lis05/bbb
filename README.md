# Introduction
This document is a brief introduction to bbb programing.
bbb is a low level programming language designed with assembly and C in mind. It
tries to stay in between the two: it has high level constructions like loops and
variable definitions, but also allows precise memory control and nasm blocks of
code. It is compatible with ABI64 x86-64 unix-like systems, meaning it can use the
standard C library without any issues.

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
```




