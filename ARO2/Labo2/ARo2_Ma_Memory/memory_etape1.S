@ ARO2 - Labo 4

mov r0, #18
lsl r0, r0, #8
mov r1, #52
orr r0, r1

mov r2, #4
strh r0, [r2,#0]

mov r1, #2
mul r0, r1
strh r0, [r2,#1*2]

mov r1, r2
add r1, #16

ldrb r3, [r2,#0]
ldrb r4, [r2,#1]
strb r3, [r1,#0]
strb r4, [r1,#1]

ldrb r3, [r2,#2]
ldrb r4, [r2,#3]
strb r3, [r1,#2]
strb r4, [r1,#3]
