/*
; In my expectation,
; #0x68 -> h
; #0x65 -> e
; #0x6c -> l
; #0x6c -> l
; #0x6f -> o
;
; (and, I do not understand what `0x0D` & `0x0A` mean)
*/

.globl _start
_start:
    ldr r0,=0x101f1000
    mov r1,#0x68
    str r1,[r0]
    mov r1,#0x65
    str r1,[r0]
    mov r1,#0x6c
    str r1,[r0]
    mov r1,#0x6c
    str r1,[r0]
    mov r1,#0x6f
    str r1,[r0]
    mov r2,#0x0D
    str r2,[r0]
    mov r2,#0x0A
    str r2,[r0]
loop:
b loop
