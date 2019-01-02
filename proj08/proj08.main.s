/********************************************************************
  Project 8 -- ARM Introduction

  Ben St. John
  CSE320
********************************************************************/

        .global main

        .text
main:   push    {lr}

        mov     r4, #0          @ Initialize character count
        mov     r5, #0          @ Initialize newLine count
        mov     r6, #0          @ Initialize whitespace count
        mov     r7, #0          @ Initialize octal count
        mov     r8, #0          @ Initialize decimal count
        mov     r9, #0          @ Initialize hexidecimal count
        mov     r10, #0         @ Initialize letter count

loop:   bl      getchar         @ Read one character (returned in r0)
        add     r4, r4, #1      @ Increment character count

ifN:    cmp     r0, #0x0a       @ Compare return value to newLine
        bne     ifT             @ If newLine not found, skip increment

thenN:  add     r5, r5, #1      @ Increment newLine count
        add     r6, r6, #1      @ Increment whitespace count

ifT:    cmp     r0, #0x09       @ Compare return value to tab
        bne     ifW             @ If tab not found, skip increment

thenT:  add     r6, r6, #1      @ Increment whitespace count

ifW:    cmp     r0, #0x20       @ Compare return value to whitespace
        bne     ifO             @ If whitespace not found, skip increment

thenW:  add     r6, r6, #1      @ Increment whitespace count

ifO:    cmp     r0, #0x2F       @ Compare return value to 0
        ble     ifD             @ If less than 0, skip

thenO:  cmp     r0, #0x38       @ Compare return value to 7
        bge     ifD             @ If greater than 7, skip
        add     r7, r7, #1      @ Increment octal count

ifD:    cmp     r0, #0x2F       @ Compare return value to 0
        ble     AtoF            @ If less than 0, skip

thenD:  cmp     r0, #0x3A       @ Compare return value to 9
        bge     AtoF            @ If greater than 9, skip
        add     r8, r8, #1      @ Increment decimal count
        add     r9, r9, #1      @ Increment hex count

AtoF:   cmp     r0, #0x40       @ Compare return value to A
        ble     aTof            @ If less than A, skip
        cmp     r0, #0x47       @ Compare return value to F
        bge     aTof            @ If hexidecimal not found, skip increment

thenA:  add     r9, r9, #1      @ Increment hexidecimal count
        add     r10, r10, #1    @ Increment letter count

aTof:   cmp     r0, #0x60       @ Compare return value to a
        ble     upL             @ If less than a, skip
        cmp     r0, #0x67       @ Compare return value to f
        bge     upL             @ If hexidecimal not found, skip increment

thena:  add     r9, r9, #1      @ Increment hexidecimal count
        add     r10, r10, #1    @ Increment letter count

upL:    cmp     r0, #0x46       @ Compare return value to F
        ble     lowL            @ If less than F, skip
        cmp     r0, #0x5b       @ Compare return value to Z
        bge     lowL            @ If greater than Z, skip

thenUp: add     r10, r10, #1    @ Increment letter count

lowL:   cmp     r0, #0x66       @ Compare return value to f
        ble     endif           @ If less than f, skip
        cmp     r0, #0x7b       @ Compare return value to z
        bge     endif           @ If greater than z, skip

thenL:  add     r10, r10, #1    @ Increment letter count

endif:  cmp     r0, #-1         @ Compare return value to EOF
        beq     end             @ When EOF found, exit loop
  
        b       loop            @ Branch to top of loop

end:    ldr     r0, =fmt2       @ First arg  -- address of format string
        mov     r1, r4          @ Second arg -- character count
        bl      printf          @ Display the two counts

        ldr     r0, =fmt3       @ First arg  -- address of format string
        mov     r1, r5          @ Second arg -- character count
        bl      printf          @ Display the two counts

        ldr     r0, =fmt4       @ First arg  -- address of format string
        mov     r1, r6          @ Second arg -- character count
        bl      printf          @ Display the two counts

        ldr     r0, =fmt5       @ First arg  -- address of format string
        mov     r1, r7          @ Second arg -- character count
        bl      printf          @ Display the two counts

        ldr     r0, =fmt6       @ First arg  -- address of format string
        mov     r1, r8          @ Second arg -- character count
        bl      printf          @ Display the two counts

        ldr     r0, =fmt7       @ First arg  -- address of format string
        mov     r1, r9          @ Second arg -- character count
        bl      printf          @ Display the two counts

        ldr     r0, =fmt8       @ First arg  -- address of format string
        mov     r1, r10         @ Second arg -- character count
        bl      printf          @ Display the two counts


        pop     {lr}
        bx      lr

fmt1:   .asciz  "\nEnter a line of text: "
fmt2:   .asciz  "\nTotal number of characters: %d"
fmt3:   .asciz  "\nNumber of newline characters: %d"
fmt4:   .asciz  "\nNumber of whitespace characters: %d"
fmt5:   .asciz  "\nNumber of octal digits: %d"
fmt6:   .asciz  "\nNumber of decimal digits: %d"
fmt7:   .asciz  "\nNumber of hexidecimal digits: %d"
fmt8:   .asciz  "\nNumber of letters: %d"
