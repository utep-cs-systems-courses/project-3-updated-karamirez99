	.arch msp430g2553
	.align 2
	
	.data
state:	.byte 0
	
	.align 2
brightness_state:	.byte 0
	
	.text
	.extern on_ratio
	.extern red_on
	.extern led_changed
	.extern led_update
	.global light_advance
	.global toggle_red
	.global show_redLED
	
toggle_red:
	cmp #0, &on_ratio       ;on ratio of 0 is no light
	jnz condition2		
	mov #0, &red_on		;turn off red led
	mov.b #1, r12
	jmp end
	
condition2:
	cmp.b #1, r12		
	jne condition3		;if given value is one, start of light cycle
	mov #1, &red_on  	;turn on REd led
	mov.b #1, r12		;signal led change
	jmp end

condition3:
	mov.b &on_ratio, r13   
	add.b #1, r13
	cmp.b r13, r12
	jne noChange           	;when value is at on_ratio, end of light cycle
	mov #0, &red_on
	mov.b #1, r12		
	jmp end
	
noChange:
	mov.b #0, r12
	jmp end


show_redLED:
	sub #1, r1		;space for char 'changed' variable
	mov.b #0, 0(r1)

	mov.b &brightness_state, r12 ;prepare parameter for function call
	call #toggle_red
	mov.b r12,0(r1)		;move return value into 'changed'
	
	bis.b 0(r1), &led_changed
	cmp.b #4, &brightness_state
	JL incrementState 
	mov.b #1, &brightness_state
	jmp reset
	
incrementState:
	add.b #1, &brightness_state
reset:
	add #1, r1
	call #led_update
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
	add r12, r12  		;array stride mult by 2 for position in jt
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
