/******************************************************************************
  Given two objects of type "int" (4-byte twos complement integer values),
  cast them to type "float" (4-byte single precision floating point values)
  and then use FDIVS to calculate the quotient.

  Translation:

    gcc /user/cse320/Projects/project11.fdivs.s

  Execution:

    gdb a.out
    (gdb) break done
    (gdb) run
    (gdb) info float
    (gdb) info registers
******************************************************************************/

	.data
A:	.word	15
B:	.word	20
X:	.single 0r0.0

	.global	main

	.text
main:
	push	{lr}

// Get integer value of A, convert to single precision floating point

	ldr	r0, =A		@ Get address of A
	ldr	r1, [r0]	@ Get value of A
	fmsr	s0, r1		@ Copy value of A to FPU register
	fsitos	s1, s0		@ Covert from int to float

// Get integer value of B, convert to single precision floating point

	ldr	r2, =B		@ Get value of B
	ldr	r3, [r2]	@ Get value of B
	fmsr	s2, r3		@ Copy value of B to FPU register
	fsitos	s3, s2		@ Covert from int to float

// Perform single precision floating point division

	fdivs	s4, s1, s3	@ Divide

// Store result in memory as variable X

	ldr	r4, =X		@ Get address of X
	fsts	s4, [r4]	@ Store result at X

done:
	pop	{lr}
	bx	lr