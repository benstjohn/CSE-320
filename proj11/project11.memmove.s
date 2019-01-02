
/******************************************************************************
  Given two 12-byte records, use "memmove" to copy one record over the top
  of the other record, then display that area of memory.

  Translation:

    gcc /user/cse320/Projects/project11.memmove.s /user/cse320/lib/memlib.o
******************************************************************************/

	.global	main
	
	.text
	.balign	4
main:
	push	{lr}
 
// Display two records (12 bytes each)

	ldr	r0, =pointA	@ Starting address
	mov	r1, #24		@ Number of bytes to display
	mov	r2, #12		@ Number of bytes per line
	bl	display		@ Call function display

// Use memmove to copy second record over first record

	ldr	r0, =pointA	@ Destination address
	ldr	r1, =pointB	@ Source address
	mov	r2, #12		@ Number of bytes to copy
	bl	memmove		@ Call function memmove
 
// Display the two records again

	ldr	r0, =pointA	@ Starting address
	mov	r1, #24		@ Number of bytes to display
	mov	r2, #12		@ Number of bytes per line
	bl	display		@ Call function display

	pop	{lr}
	bx	lr
 
	.data
	.balign	4
pointA:
	.byte	'A'
	.balign	4
	.word	12, 16
pointB:
	.byte	'B'
	.balign	4
	.word	19, 14
 