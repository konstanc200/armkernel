.global _start
_start:

ldr r0,=0x101f1000
mov r1,#1
add r1, r1, #48
add r2, r2, #10

top: 
	cmp r1, #55
	bgt idle_loop 
	str r1, [r0]
	add r1, r1,#1
	str r2, [r0]
	b top


idle_loop:  
	b idle_loop
