## C++ Build Process

### C Build Process

#### Header Trees

We can get headers used for compilation as a tree structure. (I am using Mac OSX.)

`-H` option enables us to see a header graph.

```
$ gcc-8 -H -O0 -std=c99 -g -c -o simple.o simple.c
. /usr/local/Cellar/gcc/8.2.0/lib/gcc/8/gcc/x86_64-apple-darwin18.0.0/8.2.0/include-fixed/stdio.h
.. /usr/local/Cellar/gcc/8.2.0/lib/gcc/8/gcc/x86_64-apple-darwin18.0.0/8.2.0/include/stdarg.h
.. /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h
... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h
.... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h
.... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h
... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h
.... /usr/local/Cellar/gcc/8.2.0/lib/gcc/8/gcc/x86_64-apple-darwin18.0.0/8.2.0/include-fixed/AvailabilityInternal.h
... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h
.... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h
..... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h
...... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/i386/_types.h
..... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h
... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h
.... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h
..... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/i386/types.h
...... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h
...... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h
...... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h
...... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h
...... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h
...... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h
...... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h
...... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h
...... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h
....... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h
...... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h
... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h
... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h
... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h
.. /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h
.. /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h
.. /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/secure/_stdio.h
... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/secure/_common.h
. add.h
```

#### objdump

After that, `objdump` it.

```
$ objdump -d -r simple.o

simple.o:       file format Mach-O 64-bit x86-64

Disassembly of section __TEXT,__text:
_main:
       0:       55      pushq   %rbp
       1:       48 89 e5        movq    %rsp, %rbp
       4:       48 83 ec 10     subq    $16, %rsp
       8:       89 7d fc        movl    %edi, -4(%rbp)
       b:       48 89 75 f0     movq    %rsi, -16(%rbp)
       f:       be 06 00 00 00  movl    $6, %esi
      14:       bf 05 00 00 00  movl    $5, %edi
      19:       e8 00 00 00 00  callq   0 <_main+0x1e>
                000000000000001a:  X86_64_RELOC_BRANCH  _add
      1e:       be 06 00 00 00  movl    $6, %esi
      23:       89 c7   movl    %eax, %edi
      25:       e8 00 00 00 00  callq   0 <_main+0x2a>
                0000000000000026:  X86_64_RELOC_BRANCH  _sub
      2a:       89 c6   movl    %eax, %esi
      2c:       48 8d 3d 00 00 00 00    leaq    (%rip), %rdi
                000000000000002f:  X86_64_RELOC_SIGNED  lC0
      33:       b8 00 00 00 00  movl    $0, %eax
      38:       e8 00 00 00 00  callq   0 <_main+0x3d>
                0000000000000039:  X86_64_RELOC_BRANCH  _printf
      3d:       b8 00 00 00 00  movl    $0, %eax
      42:       c9      leave
      43:       c3      retq
```

#### Symbol tables

See symbol tables in object file (named as `*.o`)

```
$ cat add.sym
00000000000000a0 s EH_frame1
0000000000000000 T _add
0000000000000014 T _sub
```

```
$ cat simple.sym
0000000000000090 s EH_frame1
                 U _add
0000000000000000 T _main
                 U _printf
                 U _sub
0000000000000044 s lC0
```

### C++ build process

Compared to C, C++ has `template` and `mangling`.

`mangling` is to edit the name for symbol tables.

Take a look at `mangling` system.

Create `mangling.cpp` and compile it with C++ compiler (In my environment, it's `g++-8`).

After that, `nm` it.

```
$ nm mangling.o

0000000100000e43 T __Z3addPKiRS_
0000000100000e5f T __Z3addff
0000000100000e2f T __Z3addii
0000000100000e79 T __ZN4manu3addEii
0000000100000000 T __mh_execute_header
0000000100000e1b T _add_c
0000000100000e8d T _main
                 U dyld_stub_binder
```

Why does C++ mangle function names on a symbol table?

It is because the same name functions with different argument types are able to be defined in C++.
