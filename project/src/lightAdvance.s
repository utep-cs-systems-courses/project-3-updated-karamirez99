	.arch msp430g2553
	.p2align 1,0
	
	.data
state:	.byte 0

	.text
	.align 2
	.extern on_ratio
	.extern red_on
	.global light_advance
	.global toggle_red

toggle_red:
	cmp #0, &on_ratio
	jnz condition2
	mov #0, &red_on
	mov.b #1, r12
	jmp end
	
condition2:
	cmp #1, r12
	jne condition3
	mov #1, &red_on
	mov.b #1, r12
	jmp end

condition3:
	mov.b &on_ratio, r13
	add.b #1, r13
	cmp r13, r12
	jne noChange
	mov #0, &red_on
	mov.b #1, r12
	jmp end
	
noChange:
	mov #0, r12
	jmp end
	
Jt:	.word case0
	.word case1
	.word case2
	.word case3
	.word default
	
light_advance:
	cmp.b #4, &state
	jc default

	mov &state, r12
	add r12, r12
	mov Jt(r12), r0
	
case0:
	mov.b #1, &state
	mov.b #1, &on_ratio
	jmp end
case1:
	mov.b #2, &state
	mov.b #2, &on_ratio
	jmp end
case2:
	mov.b #3, &state
	mov.b #3, &on_ratio
	jmp end
case3:
	mov.b #0, &state
	mov.b #4, &on_ratio
	jmp end
default:
end:
	pop r0
