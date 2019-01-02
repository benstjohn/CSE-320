/******************************************************************************
 Ben St. John
 Project 11 - Support.s
 CSE 320
******************************************************************************/
    	.global search
        .global delete
        .global insert
        .data
x:	.word 42
y:      .word 42
z:	.single 0r0.0
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
        bgt     fail

        ldrh    r11, [r9, #0]    @ contents of jersey field
    
        cmp     r11, r5
        beq     success
        bgt     fail 

        add     r10, r10, #1      @ increment index by one
        add     r9, r9, #40       @ offset <== index * element size
        b       loop

success:
        mov     r0, #1
        str     r9, [r6]
        b       endloop
fail:   
        mov     r0, #0
        str     r9, [r6]

endloop:
        pop     {r4,r5,r6,r7,r8,r9,r10,r11,lr}
        bx      lr

delete:
        push    {r4,r5,r6,r7,r8,r9,r10,r11,lr}
        mov	r4, r0             @ base address of table
        mov     r5, r1             @ jersey number we're looking for
        ldr     r2, =x             @ put some sauce in here

        bl      search             @ calling the search function

        cmp     r0, #0             @ if search didn't find anything
        beq     delFail            @ break to failure

delSuc:
        @calculating number of bytes to move
        ldr     r6, =x          @ pointer to our thing (A)
        ldr     r6, [r6]

        ldrh    r10, [r4, #2]   @ count val
        ldr     r11, [r4, #4]   @ starting address
        sub     r10, r10, #1    @ ((count - 1) * 40) - (addr-start)

        mov     r9, #40     

        mul     r8, r10, r9     @ (count-1) * 40
        sub     r9, r6, r11
        sub     r9, r8, r9
       
        mov	r0, r6	        @ Destination address
        mov     r7, r6
        add     r7, r7, #40     @ Getting source address
	mov	r1, r7	        @ Source address
	mov	r2, r9		@ Number of bytes to copy
	
        bl	memmove		@ Call function memmove

        sub     r10, r10, #1
        strh    r10, [r4, #2]

        mov     r0, #1
        b      endDel

delFail:
        mov     r0, #0

endDel:
        pop     {r4,r5,r6,r7,r8,r9,r10,r11,lr}
        bx      lr

insert:
        push    {r4,r5,r6,r7,r8,r9,r10,r11,lr}
        mov	r4, r0             @ base address of table
        mov     r5, r1             @ jersey number we're looking for
        mov     r6, r2             @ pointer to name of player
        mov     r7, r3             @ number of games played
        ldr     r8, [sp, #36]      @ number of goals scored
        ldr     r2, =x             @ put some sauce in here

        bl      search             @ calling the search function

        cmp     r0, #1             @ if search found anything
        beq     insFail            @ break to failure
        
        mov     r0, #1
insSuc:
        @ Make sure we haven't reached capacity
        ldrh    r3, [r4]
        ldrh    r2, [r4, #2]
        cmp     r2, r3
        bge     insFail

        @ Finding the Average
        fmsr	s0, r7		@ Copy numGames FPU register
	fsitos	s1, s0		@ Covert from int to float

       
	fmsr	s2, r8		@ Copy numGoals FPU register
	fsitos	s3, s2		@ Covert from int to float

        fdivs	s4, s3, s1	@ Divide goals/games

	ldr	r3, =z 	        @ Get address of z
	fsts	s4, [r3]	@ Store result at z

        @ Found the average

        @ LEGACY CODE
        ldr     r10, =x          @ pointer to next player
        ldr     r10, [r10]
        
        ldr     r2, [r4, #4]
        ldrh    r11, [r4, #2]

        mov     r0, #40
        mul     r1, r11, r0     @ count * 40
        add     r9, r1, r2      @ (count * 40) + start

        add     r0, r10, #40    @ dest is r0 + 40
        mov     r1, r10         @ source is r10
        sub     r2, r9, r1      @ r2 = count *40 + start
        
        bl	memmove		@ Call function memmove

        @ decrease the count
        add     r11, r11, #1
        strh    r11, [r4, #2]

        @ Storing name
        sub     r0, r0, #40
        mov     r11, r0
        add     r0, #2
        mov     r1, r6
        mov     r2, #25
        bl      memmove
       
        
        @ store goals scored
        ldr     r8, [sp, #36]      @ number of goals scored
        strh    r8, [r11, #30]

        @ store assists
        ldr     r9, [sp, #40]      @ number of assists scored
        strh    r9, [r11, #32]

        @ store jersey number
        strh    r5, [r11, #0] 

        @ store games played
        strh    r7, [r11, #28]

        @ store points scored
        add     r9, r8, r9      @ number of points scored
        strh    r9, [r11, #34]

        @ store average
        ldr	r3, =z 	        @ Get address of z
	ldr	r3, [r3]	@ Store result at z
        str     r3, [r11, #36]

        @ make it successful
        mov     r0, #1
        b       endIns

insFail:
        mov     r0, #0

endIns:
        pop     {r4,r5,r6,r7,r8,r9,r10,r11,lr}
        bx      lr


