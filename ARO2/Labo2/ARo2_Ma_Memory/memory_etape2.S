@ ARO2 - Labo 4

mov r5, #0xfe

	mov r1, #0x26
	bl FONCTION_A
	add r4,r2,#3
mov r0, #0xCA
b END

	.org 0x20
	FONCTION_A:
strh r6, [r5, #0]
sub r5, r5, #2
	bl FONCTION_B
	mov r2, #0xff
	and r2, r1
add r5, r5, #2
ldrh r6, [r5, #0]
	mov r7, r6

	.org 0x40
	FONCTION_B:
strh r6, [r5, #0]
sub r5, r5, #2
	lsl r2, r1, #4
	bl FONCTION_C
add r5, r5, #2
ldrh r6, [r5, #0]
	mov r7, r6

	.org 0x60
	FONCTION_C:
strh r6, [r5, #0]
sub r5, r5, #2
	mov r1, #1
	orr r2, r1
add r5, r5, #2
ldrh r6, [r5, #0]
	mov r7, r6 
	
.org 0x80
END:
b END
