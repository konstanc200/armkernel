.global _start
_start:

IMPORT foo_c 

foo_asm push {lr} ; save the Load Register before calling the subroutine 
ldr r0, =0x01010101 
ldr r1, =0x02020202 
bl foo_c
 
; call foo_c pop {pc} ; puts the PUSHed value of the load register into the Program Counter
: b . 


