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

	@ R4 = R0 - 0 (update flags)
	subs r4, r0, #0x0
	@ if(R0 <= 0) goto .L3 (which returns 0)
	ble .L3
	@modified by arno
	mov r3, #0x0
	mov r5, #0x1
	mov r0, #0x1
loop:
	subs r4, r4, #0x1
	beq loop_end
	add r0, r3, r5
	mov r3, r5
	mov r5, r0
	b loop

loop_end:
	pop {r3, r4, r5, pc}		@EPILOG

	@ END CODE MODIFICATION
.L3:
	mov r0, #0x0			@ R0 = 0
	pop {r3, r4, r5, pc}		@ EPILOG

	.size fibonacci, .-fibonacci
	.end
