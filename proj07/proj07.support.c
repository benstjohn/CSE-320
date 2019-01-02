// Proj07.support.c
// Ben St. John
// CSE 320
//#include "/user/cse320/Projects/project07.support.h"
#include "project07.support.h"
#include <stdio.h>
#include <string.h>

void decode(unsigned int a, char b[])
{
    unsigned int leading_bits = ((a & 0xec000000) >> 26);
    unsigned int i_bit = ((a & 0x02000000) >> 25);
    unsigned int opcode = ((a & 0x01e00000) >> 21);
    unsigned int s_bit = ((a & 0x00100000) >> 20);
    unsigned int rn = ((a & 0x000f0000) >> 16);
    unsigned int rd = ((a & 0x0000f000) >> 12);
    unsigned int unused_i = ((a & 0x00000f00) >> 8);
    unsigned int unused = ((a & 0x00000ff0) >> 4);
    unsigned int immediate_val = (a & 0x00000ff); //when I=1
    unsigned int rm = (a & 0x000000f);            //when I = 0
    char reg_name[80];
    char op_name[80];

    if (leading_bits != 0x38)
    {
        strcpy(b, "ERROR - leading bits are invalid");
    }
    else if ((unused_i != 0x00 && i_bit) || (unused != 0x0000 && !i_bit))
    {
        strcpy(b, "ERROR - unused bits should be 0");
    }
    else
    {
        switch (opcode)
        {
        case 0x0: //and
            (s_bit) ? (sprintf(op_name, "ands ")) : (sprintf(op_name, "and "));
            if (i_bit)
            { //use immediate val
                sprintf(reg_name, "%s r%d, r%d, #0x%x", op_name, rd, rn, immediate_val);
            }
            else
            { //use the normal val
                sprintf(reg_name, "%s r%d, r%d, r%d", op_name, rd, rn, rm);
            }
            strcpy(b, reg_name);
            break;
        case 0x1: //eor
            (s_bit) ? (sprintf(op_name, "eors ")) : (sprintf(op_name, "eor "));
            if (i_bit)
            { //use immediate val
                sprintf(reg_name, "%s r%d, r%d, #0x%x", op_name, rd, rn, immediate_val);
            }
            else
            { //use the normal val
                sprintf(reg_name, "%s r%d, r%d, r%d", op_name, rd, rn, rm);
            }
            strcpy(b, reg_name);
            break;
        case 0x2: //sub
            (s_bit) ? (sprintf(op_name, "subs ")) : (sprintf(op_name, "sub "));
            if (i_bit)
            { //use immediate val
                sprintf(reg_name, "%s r%d, r%d, #0x%x", op_name, rd, rn, immediate_val);
            }
            else
            { //use the normal val
                sprintf(reg_name, "%s r%d, r%d, r%d", op_name, rd, rn, rm);
            }
            strcpy(b, reg_name);
            break;
        case 0x3: //rsb
            (s_bit) ? (sprintf(op_name, "rsbs ")) : (sprintf(op_name, "rsb "));
            if (i_bit)
            { //use immediate val
                sprintf(reg_name, "%s r%d, r%d, #0x%x", op_name, rd, rn, immediate_val);
            }
            else
            { //use the normal val
                sprintf(reg_name, "%s r%d, r%d, r%d", op_name, rd, rn, rm);
            }
            strcpy(b, reg_name);
            break;
        case 0x4: //add
            (s_bit) ? (sprintf(op_name, "adds ")) : (sprintf(op_name, "add "));
            if (i_bit)
            { //use immediate val
                sprintf(reg_name, "%s r%d, r%d, #0x%x", op_name, rd, rn, immediate_val);
            }
            else
            { //use the normal val
                sprintf(reg_name, "%s r%d, r%d, r%d", op_name, rd, rn, rm);
            }
            strcpy(b, reg_name);
            break;
        case 0x5: //adc
            (s_bit) ? (sprintf(op_name, "adcs ")) : (sprintf(op_name, "adc "));
            if (i_bit)
            { //use immediate val
                sprintf(reg_name, "%s r%d, r%d, #0x%x", op_name, rd, rn, immediate_val);
            }
            else
            { //use the normal val
                sprintf(reg_name, "%s r%d, r%d, r%d", op_name, rd, rn, rm);
            }
            strcpy(b, reg_name);
            break;
        case 0x6: //sbc
            (s_bit) ? (sprintf(op_name, "sbcs ")) : (sprintf(op_name, "sbc "));
            if (i_bit)
            { //use immediate val
                sprintf(reg_name, "%s r%d, r%d, #0x%x", op_name, rd, rn, immediate_val);
            }
            else
            { //use the normal val
                sprintf(reg_name, "%s r%d, r%d, r%d", op_name, rd, rn, rm);
            }
            strcpy(b, reg_name);
            break;
        case 0x7: //rsc
            (s_bit) ? (sprintf(op_name, "rscs ")) : (sprintf(op_name, "rsc "));
            if (i_bit)
            { //use immediate val
                sprintf(reg_name, "%s r%d, r%d, #0x%x", op_name, rd, rn, immediate_val);
            }
            else
            { //use the normal val
                sprintf(reg_name, "%s r%d, r%d, r%d", op_name, rd, rn, rm);
            }
            strcpy(b, reg_name);
            break;
        case 0x8: //tst
            if (s_bit)
            {
                if (rd != 0x0)
                {
                    strcpy(b, "ERROR - destination bits should be 0");
                }
                else
                {
                    if (i_bit)
                    { //use immediate val
                        sprintf(reg_name, "%s r%d, #0x%x", "tst", rn, immediate_val);
                    }
                    else
                    { //use the normal val
                        sprintf(reg_name, "%s r%d, r%d", "tst", rn, rm);
                    }
                    strcpy(b, reg_name);
                }
            }
            else
            {
                strcpy(b, "ERROR - S bit must be 1 for this instruction");
            }
            break;
        case 0x9: //teq
            if (s_bit)
            {
                if (rd != 0x0)
                {
                    strcpy(b, "ERROR - destination bits should be 0");
                }
                else
                {
                    if (i_bit)
                    { //use immediate val
                        sprintf(reg_name, "%s r%d, #0x%x", "teq", rn, immediate_val);
                    }
                    else
                    { //use the normal val
                        sprintf(reg_name, "%s r%d, r%d", "teq", rn, rm);
                    }
                    strcpy(b, reg_name);
                }
            }
            else
            {
                strcpy(b, "ERROR - S bit must be 1 for this instruction");
            }
            break;
        case 0xa: //cmp
            if (s_bit)
            {
                if (rd != 0x0)
                {
                    strcpy(b, "ERROR - destination bits should be 0");
                }
                else
                {
                    if (i_bit)
                    { //use immediate val
                        sprintf(reg_name, "%s r%d, #0x%x", "cmp", rn, immediate_val);
                    }
                    else
                    { //use the normal val
                        sprintf(reg_name, "%s r%d, r%d", "cmp", rn, rm);
                    }
                    strcpy(b, reg_name);
                }
            }
            else
            {
                strcpy(b, "ERROR - S bit must be 1 for this instruction");
            }
            break;
        case 0xb: //cmn
            if (s_bit)
            {
                if (rd != 0x0)
                {
                    strcpy(b, "ERROR - destination bits should be 0");
                }
                else
                {
                    if (i_bit)
                    { //use immediate val
                        sprintf(reg_name, "%s r%d, #0x%x", "cmn", rn, immediate_val);
                    }
                    else
                    { //use the normal val
                        sprintf(reg_name, "%s r%d, r%d", "cmn", rn, rm);
                    }
                    strcpy(b, reg_name);
                }
            }
            else
            {
                strcpy(b, "ERROR - S bit must be 1 for this instruction");
            }
            break;
        case 0xc: //orr
            (s_bit) ? (sprintf(op_name, "orrs ")) : (sprintf(op_name, "orr "));
            if (i_bit)
            { //use immediate val
                sprintf(reg_name, "%s r%d, r%d, #0x%x", op_name, rd, rn, immediate_val);
            }
            else
            { //use the normal val
                sprintf(reg_name, "%s r%d, r%d, r%d", op_name, rd, rn, rm);
            }
            strcpy(b, reg_name);
            break;
        case 0xd: //mov
            if (rn != 0x0)
            {
                strcpy(b, "ERROR - Rn bits should be 0");
            }
            else
            {
                (s_bit) ? (sprintf(op_name, "movs ")) : (sprintf(op_name, "mov "));
                if (i_bit)
                { //use immediate val
                    sprintf(reg_name, "%s r%d, #0x%x", op_name, rd, immediate_val);
                }
                else
                { //use the normal val
                    sprintf(reg_name, "%s r%d, r%d", op_name, rd, rm);
                }
                strcpy(b, reg_name);
            }
            break;
        case 0xe: //bic
            (s_bit) ? (sprintf(op_name, "bics ")) : (sprintf(op_name, "bic "));
            if (i_bit)
            { //use immediate val
                sprintf(reg_name, "%s r%d, r%d, #0x%x", op_name, rd, rn, immediate_val);
            }
            else
            { //use the normal val
                sprintf(reg_name, "%s r%d, r%d, r%d", op_name, rd, rn, rm);
            }
            strcpy(b, reg_name);
            break;
        case 0xf: //mvn
            if (rn != 0x0)
            {
                strcpy(b, "ERROR - Rn bits should be 0");
            }
            else
            {
                (s_bit) ? (sprintf(op_name, "mvns ")) : (sprintf(op_name, "mvn "));
                if (i_bit)
                { //use immediate val
                    sprintf(reg_name, "%s r%d, #0x%x", op_name, rd, immediate_val);
                }
                else
                { //use the normal val
                    sprintf(reg_name, "%s r%d, r%d", op_name, rd, rm);
                }
                strcpy(b, reg_name);
            }
            break;
        }
    }
}
