	.syntax unified
	.arch armv7-a
	.text
	.align 2
	.thumb
	.thumb_func

	.global fibonacci
	.type fibonacci, function

fibonacci:
	@ ADD/MODIFY CODE BELOW
	@ PROLOG
	push {r3, r4, r5, lr}

	@ if(R0 <= 0) goto .L3 (which returns 0)
	cmp r0, #0
	ble .L3

	@ R3 = 1
	mov r3, #1
	@ R4 = 0
	mov r4, #0
	@ R5 = R0 (which counts loop)
	mov r5, r0
loop:
	@ R5 = R5 - 1
	subs r5, r5, #1
	@ if(R5 <= 0) goto .L3 (which returns R0)
	beq .L3

	@ R0 = R3 + R4
	add r0, r3, r4
	@ R4 = R3
	mov r4, r3
	@ R3 = R0
	mov r3, r0

	@ goto loop
	b loop

	@ END CODE MODIFICATION
.L3:

	pop {r3, r4, r5, pc}		@ EPILOG

	.size fibonacci, .-fibonacci
	.end
