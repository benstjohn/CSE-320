// Proj12.support.c
// Ben St. John
// CSE 320
#include "/user/cse320/Projects/project12.support.h"
#include <stdio.h>

unsigned update(unsigned PC, unsigned IR, unsigned CPSR)
{
    PC = PC + 4;

    unsigned category = (0x0c000000 & IR) >> 26;
    unsigned cond = (0xf0000000 & IR) >> 28;
    unsigned l_bit = (0x02000000 & IR) >> 25;
    unsigned simm24 = (0x00ffffff & IR);

    signed sign_extend = (simm24 << 2);
    sign_extend = (sign_extend << 6) >> 6;

    unsigned n_bit = (CPSR & 0x80000000) >> 31;
    unsigned z_bit = (CPSR & 0x40000000) >> 30;
    unsigned c_bit = (CPSR & 0x20000000) >> 29;
    unsigned v_bit = (CPSR & 0x10000000) >> 28;
    unsigned final = 0;

    if (category == 2)
    { //category is branch
        if (l_bit == 1)
        {

            switch (cond)
            {
            case 0: //0000
                (z_bit == 1) ? (final = PC + sign_extend) : (final = PC);
                break;
            case 1: //0001
                (z_bit == 0) ? (final = PC + sign_extend) : (final = PC);
                break;
            case 2: //0010
                (c_bit == 1) ? (final = PC + sign_extend) : (final = PC);
                break;
            case 3: //0011
                (c_bit == 0) ? (final = PC + sign_extend) : (final = PC);
                break;
            case 4: //0100
                (n_bit == 1) ? (final = PC + sign_extend) : (final = PC);
                break;
            case 5: //0101
                (n_bit == 0) ? (final = PC + sign_extend) : (final = PC);
                break;
            case 6: //0110
                (v_bit == 1) ? (final = PC + sign_extend) : (final = PC);
                break;
            case 7: //0111
                (v_bit == 0) ? (final = PC + sign_extend) : (final = PC);
                break;
            case 8: //1000
                (c_bit && !z_bit) ? (final = PC + sign_extend) : (final = PC);
                break;
            case 9: //1001
                (!c_bit || z_bit) ? (final = PC + sign_extend) : (final = PC);
                break;
            case 10: //1010
                (n_bit == v_bit) ? (final = PC + sign_extend) : (final = PC);
                break;
            case 11: //1011
                (n_bit != v_bit) ? (final = PC + sign_extend) : (final = PC);
                break;
            case 12: //1100
                (!z_bit && (n_bit == v_bit)) ? (final = PC + sign_extend) : (final = PC);
                break;
            case 13: //1101
                (z_bit && n_bit != v_bit) ? (final = PC + sign_extend) : (final = PC);
                break;
            case 14: //1110
                final = PC + sign_extend;
                break;
            default: //1111
                final = 0;
                break;
            }
        }
    }
    else if (category == 1 || category == 0)
    { //category is data processing/movement
        final = PC;
    }
    //should only reach this for category == 3
    return final;
}
