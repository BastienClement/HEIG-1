@----------------------------------------------------------
@Labo ARO2 - Micro architecture DECODE
@ HEIG-VD / Institut REDS
@ Prof. M.Starkier
@ Ass. Yanick Saugy, Vincent Theurillat
@----------------------------------------------------------
@	Auteur	:	
@	Date	  :25.04.2013
@----------------------------------------------------------
@
@	Test de toutes les instructions pour le bloc execute
@
@----------------------------------------------------------


mov r0, #2
mov r1, #3

lsl r2, r1, #2
lsl r2, r2, r0
lsr r3, r2, #2
lsr r1, r1, r0

and r0, r1
orr r0, r2
eor r0, r2
mvn r4, r1

add r3, r0, #5
add r3, r1, r2
sub r4, r3, #6
sub r4, r4, r0

mov r1, #3
mov r2, #2
mul r1, r2
