
/********************************************************************
  Example #25 -- ARM data organization (arrays of records)
********************************************************************/

        .global print_all
        .text
        .balign 4
print_all:
        push    {r4,r5,r6,r7,r8,lr}

        mov     r4, r0          @ 1st argument: base address of array
        mov     r5, r1          @ 2nd argument: number of records

        ldr     r0, =fmt1       @ print the column headers
        bl      printf

        mov     r6, #0          @ initialize index to zero
loop:
        cmp     r6, r5          @ compare index and number of elements
        bge     endloop

        lsl     r7, r6, #4      @ offset <== index * element size
        add     r8, r4, r7      @ record address <== base + offset

        ldr     r0, =fmt2       @ print the contents of one record
        add     r1, r8, #0      @ address of name field
        ldrh    r2, [r8, #12]   @ contents of exam1 field
        ldrh    r3, [r8, #14]   @ contents of exam2 field
        bl      printf

        add     r6, r6, #1      @ increment index by one
        b       loop
endloop:
        ldr     r0, =fmt3       @ print a blank line
        bl      printf

        pop     {r4,r5,r6,r7,r8,lr}
        bx      lr

fmt1:   .ascii  "\n"
        .ascii  "Student name  Exam 1  Exam 2\n"
        .asciz  "------------  ------  ------\n"

fmt2:   .asciz  "%-12s  %6d  %6d\n"

fmt3:   .asciz  "\n"
        .balign 4
