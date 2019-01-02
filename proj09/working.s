
/********************************************************************
  Ben St. John
  Project 9
********************************************************************/

        .global negate
        .global absolute
        .global add
        .global sub
        .global mul
        .global divide
        .global power
        .global factorial

        .text
negate:                                 @negate all values
        push    {r4,r5,r6,r7,r8,lr}

        mov     r4, r0
        mov     r5, #0
        subs    r4, r5, r4

        bvs     overflow                @break to overflow

        mov     r0, r4
        bl      done                    @break to final pop

absolute:                               @absolute val of param
        push    {r4,r5,r6,r7,r8,lr}
        
        mov     r4, r0
        cmp     r4, #0x0
        bge     returnAbs               @break if already pos

        mov     r5, #0
        sub     r4, r5, r4

returnAbs:
        mov     r0, r4
        bl      done                    @break to final pop

add:                                    @adds two params
        push    {r4,r5,r6,r7,r8,lr}
        mov     r4, r0
        mov     r5, r1

        adds     r6, r4, r5
        bvs     overflow                @checks s-bit for overflow

        mov     r0, r6
        bl      done                    @break to final pop

sub:                                    @subtracts two params
        push    {r4,r5,r6,r7,r8,lr}
        mov     r4, r0
        mov     r5, r1

        sub     r6, r4, r5
        bvs     overflow                @checking s-bit for overflow

        mov     r0, r6
        bl      done                    @break to final pop

mul:                                    @multiply two params
        push    {r4,r5,r6,r7,r8,lr}
        mov     r4, r0
        mov     r5, r1

        smull   r6, r7, r4, r5          @signed multiply

        cmp     r6, #0                  @check result sign
        bge     ifPos                   @if pos, check for all 0

        cmp     r6, #-1                 @check result sign
        ble     ifNeg                   @if neg, check for all 1

ifPos:                                  @checking for overflow
        cmp     r7, #0
        bne     overflow                
        bl      finMul
ifNeg:                                  @checking for overflow
        cmp     r7, #0xffffffff
        bne     overflow

finMul:                                 @return result
        mov     r0, r6
        bl      done                    @break to final pop

divide:                                 @divides to params
        push    {r4,r5,r6,r7,r8,lr}
        mov     r4, r0
        mov     r5, r1
        cmp     r5, #0

        beq     overflow                @can't divide by 0

        sdiv    r6, r4, r5              @signed divide

        mov     r0, r6
        bl      done                    @break to final pop

power:                                  @power function of two params
        push    {r4,r5,r6,r7,r8,lr}
        mov     r4, r0
        mov     r5, r0
        mov     r6, r1

        cmp     r6, #0                  @checks if power is 0
        beq     isOne                   @will always be one
        cmp     r6, #-1                 @checks for negative exp
        ble     overflow                @return error
loop:
        cmp     r6, #1
        beq     endPow

        mov     r0, r4                  @setting first param for mul
        mov     r1, r5                  @setting second param for mul
        bl      mul                     @calling our multiply
        sub     r6, r6, #1
        mov     r4, r0
        cmp     r4, #0x80000000         @making sure it didn't overflow
        beq     done
        bl      loop
isOne:  
        mov     r4, #1
endPow:
        mov     r0, r4                  @return final answer
        bl      done                    @break to final pop

factorial:                              @factorial of given param
        push    {r4,r5,r6,r7,r8,lr}
        mov     r4, r0
        mov     r5, r0
        cmp     r5, #-1
        ble     overflow                @checks for negative factorial
repeat:
        cmp     r5, #2
        ble     endFac

        sub     r5, r5, #1
        mov     r0, r4                  @setting first param for mul
        mov     r1, r5                  @setting second param for mul
        bl      mul                     @calling our multiply
        
        mov     r4, r0
        cmp     r4, #0x80000000 
        beq     done

        bl      repeat

endFac:
        mov     r0, r4                  @setting return val
        bl      done                    @break to final pop

overflow:
        mov     r0, #0x80000000         @Return value 1 (not valid) 
done:
        pop     {r4,r5,r6,r7,r8,lr}     @popping all of our used registers
        bx      lr                      

