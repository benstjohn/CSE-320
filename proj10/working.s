    	.global search
		
	.text
        .balign 4

search:
        push    {r4,r5,r6,r7,r8,r9,r10,r11,lr}

	mov	r4, r0             @ base address of table
	mov     r5, r1             @ jersey number we're looking for
	mov	r6, r2             @ pointer to pointer where to return
        ldrh    r7, [r4, #0]       @ number of elements in table
        ldrh    r8, [r4, #2]       @ number of players
        ldr     r9, [r4, #4]       @ address of players
        mov     r10, #0            @ initialize index to zero

loop:
        cmp     r10, r8          @ compare index and number of elements
        bge     fail

        ldr     r0, =fmt2       @ print the column headers

        bl      printf

        ldrh    r11, [r9, #0]    @ contents of jersey field
    
        cmp     r11, r5
        beq     success

        add     r10, r10, #1      @ increment index by one
        add     r9, r9, #40       @ offset <== index * element size
        b       loop

success:
        mov     r0, #1
        str     r9, [r6]
        b       endloop
fail:   
        mov     r0, #0

endloop:
        pop     {r4,r5,r6,r7,r8,r9,r10,r11,lr}
        bx      lr

fmt2:   .ascii  "swag\n"