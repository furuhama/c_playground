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
