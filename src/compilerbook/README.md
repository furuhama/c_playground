## Compiler book

test1.c

```c
int main() {
    return 42;
}
```

Compile this to `test1` & Try `objdump`

```
$ gcc test1.c -o test1
$ objdump -d -M intel ./test1

./test1:     ファイル形式 mach-o-x86-64


セクション .text の逆アセンブル:

0000000100000fa5 <_main>:
   100000fa5:	55                   	push   rbp
   100000fa6:	48 89 e5             	mov    rbp,rsp
   100000fa9:	b8 2a 00 00 00       	mov    eax,0x2a
   100000fae:	5d                   	pop    rbp
   100000faf:	c3                   	ret
```

`test1.c` is equal to `test2.s`(Assembly file)

```
.intel_syntax noprefix
.global _main
_main:
        mov rax, 42
        ret
```

Try simple function.

test3.c

```c
int plus(int x, int y) {
    return x + y;
}

int main() {
    return plus(20, 22);
}
```

Objdump this

```
$ gcc test3.c -o test3
$ objdump -d -M intel ./test3

./test3:     ファイル形式 mach-o-x86-64


セクション .text の逆アセンブル:

0000000100000f4f <_plus>:
   100000f4f:   55                      push   rbp
   100000f50:   48 89 e5                mov    rbp,rsp
   100000f53:   89 7d fc                mov    DWORD PTR [rbp-0x4],edi
   100000f56:   89 75 f8                mov    DWORD PTR [rbp-0x8],esi
   100000f59:   8b 55 fc                mov    edx,DWORD PTR [rbp-0x4]
   100000f5c:   8b 45 f8                mov    eax,DWORD PTR [rbp-0x8]
   100000f5f:   01 d0                   add    eax,edx
   100000f61:   5d                      pop    rbp
   100000f62:   c3                      ret

0000000100000f63 <_main>:
   100000f63:   55                      push   rbp
   100000f64:   48 89 e5                mov    rbp,rsp
   100000f67:   be 16 00 00 00          mov    esi,0x16
   100000f6c:   bf 14 00 00 00          mov    edi,0x14
   100000f71:   e8 d9 ff ff ff          call   100000f4f <_plus>
   100000f76:   5d                      pop    rbp
   100000f77:   c3                      ret
```

Write assembly equal to `test3.c`

```
.intel_syntax noprefix
.global plus, _main

plus:
        add rsi, rdi
        mov rax, rsi
        ret

_main:
        mov rdi, 20
        mov rsi, 22
        call plus
        ret
```

### Register name

`rax`, `rsi`, `rdi`: 64-bit register

If a register name has `r` prefix, it means 64-bit register.
On the other hand, if one has `e` prefix, it means 32-bit register.

If a register name is like `r?x`(? filled with `A`, `B`, `C` or `D`), it is called `General Purpose Register`.

Registers named `rsi` or `rdi` are called `Index Registers`.
`RSI` is specially called `Source Index for string operations`,
and `RDI` is specially called `Destination Index for string operations`.

References:

- https://en.wikipedia.org/wiki/X86#64-bit
- https://en.wikipedia.org/wiki/X86#Structure
