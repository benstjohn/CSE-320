// Proj12.driver.c
// Ben St. John
// CSE 320
#include "/user/cse320/Projects/project12.support.h"
#include <stdio.h>
int main()
{

    unsigned PC;
    unsigned IR;
    unsigned CPSR;
    unsigned res;
    unsigned expected;

    PC = 0;
    IR = 0xaa000003;
    CPSR = 0x40000000;
    res = update(PC, IR, CPSR);
    expected = 0x00000010;
    printf("Branch || Cond = 1010 \n");
    printf("NZCV: 0010 \n");
    printf("===========\n");
    printf("Current PC Val: %8x\n", PC);
    printf("IR: %8x\n", IR);
    printf("CPSR: %8x\n", CPSR);
    printf("Next value of the PC: %8x\n", res);
    printf("Expected: %8x\n\n", expected);

    PC = 0x00012000;
    IR = 0xeafffff6;
    CPSR = 0x00000000;
    res = update(PC, IR, CPSR);
    expected = 0x00011fdc;
    printf("Branch || Cond = 1111 \n");
    printf("NZCV: 0000 \n");
    printf("===========\n");
    printf("Current PC Val: %8x\n", PC);
    printf("IR: %8x\n", IR);
    printf("CPSR: %8x\n", CPSR);
    printf("Next value of the PC: %8x\n", res);
    printf("Expected: %8x\n\n", expected);

    //Should return 0 - illegal machine lang (condition 15)
    PC = 0;
    IR = 0xf8000000;
    CPSR = 0x40000000;
    res = update(PC, IR, CPSR);
    expected = 0x0;
    printf("Illegal Machine Language\n");
    printf("===========\n");
    printf("Current PC Val: %8x\n", PC);
    printf("IR: %8x\n", IR);
    printf("CPSR: %8x\n", CPSR);
    printf("Next value of the PC: %8x\n", res);
    printf("Expected: %8x\n\n", expected);

    //Should return PC + 4 (cat = 00)
    PC = 0;
    IR = 0x00000000;
    CPSR = 0x40000000;
    res = update(PC, IR, CPSR);
    expected = 0x00000004;
    printf("Testing category 00\n");
    printf("===========\n");
    printf("Current PC Val: %8x\n", PC);
    printf("IR: %8x\n", IR);
    printf("CPSR: %8x\n", CPSR);
    printf("Next value of the PC: %8x\n", res);
    printf("Expected: %8x\n\n", expected);

    //Should return PC + 4 (cat = 01)
    PC = 0;
    IR = 0x04000000;
    CPSR = 0x40000000;
    res = update(PC, IR, CPSR);
    expected = 0x00000004;
    printf("Testing category 01\n");
    printf("===========\n");
    printf("Current PC Val: %8x\n", PC);
    printf("IR: %8x\n", IR);
    printf("CPSR: %8x\n", CPSR);
    printf("Next value of the PC: %8x\n", res);
    printf("Expected: %8x\n\n", expected);

    //Should return 0 (cat = 11)
    PC = 0;
    IR = 0x0c000000;
    CPSR = 0x40000000;
    res = update(PC, IR, CPSR);
    expected = 0x00000000;
    printf("Testing category 11\n");
    printf("===========\n");
    printf("Current PC Val: %8x\n", PC);
    printf("IR: %8x\n", IR);
    printf("CPSR: %8x\n", CPSR);
    printf("Next value of the PC: %8x\n", res);
    printf("Expected: %8x\n\n", expected);

    //Testing matching nzcv with 0000
    PC = 0;
    IR = 0x0b000001;
    CPSR = 0x40000000;
    res = update(PC, IR, CPSR);
    expected = 0x00000008;
    printf("Branch || Cond = 0000 \n");
    printf("NZCV: 0100 \n");
    printf("===========\n");
    printf("Current PC Val: %8x\n", PC);
    printf("IR: %8x\n", IR);
    printf("CPSR: %8x\n", CPSR);
    printf("Next value of the PC: %8x\n", res);
    printf("Expected: %8x\n\n", expected);

    //Testing matching nzcv with 0001
    PC = 0;
    IR = 0x1b000001;
    CPSR = 0x00000000;
    res = update(PC, IR, CPSR);
    expected = 0x00000008;
    printf("Branch || Cond = 0001 \n");
    printf("NZCV: 0000 \n");
    printf("===========\n");
    printf("Current PC Val: %8x\n", PC);
    printf("IR: %8x\n", IR);
    printf("CPSR: %8x\n", CPSR);
    printf("Next value of the PC: %8x\n", res);
    printf("Expected: %8x\n\n", expected);

    //Testing matching nzcv with 1001
    PC = 0;
    IR = 0x9b000001;
    CPSR = 0x00000000;
    res = update(PC, IR, CPSR);
    expected = 0x00000008;
    printf("Branch || Cond = 1001 \n");
    printf("NZCV: 0000 \n");
    printf("===========\n");
    printf("Current PC Val: %8x\n", PC);
    printf("IR: %8x\n", IR);
    printf("CPSR: %8x\n", CPSR);
    printf("Next value of the PC: %8x\n", res);
    printf("Expected: %8x\n\n", expected);

    //Testing non-matching nzcv with 0101
    PC = 0;
    IR = 0x5b000001;
    CPSR = 0x80000000;
    res = update(PC, IR, CPSR);
    expected = 0x00000004;
    printf("Branch || Cond = 0101 \n");
    printf("NZCV: 1000 \n");
    printf("===========\n");
    printf("Current PC Val: %8x\n", PC);
    printf("IR: %8x\n", IR);
    printf("CPSR: %8x\n", CPSR);
    printf("Next value of the PC: %8x\n", res);
    printf("Expected: %8x\n\n", expected);

    //Testing non-matching nzcv with 1100
    PC = 0;
    IR = 0xcb000001;
    CPSR = 0xc0000000;
    res = update(PC, IR, CPSR);
    expected = 0x00000004;
    printf("Branch || Cond = 1100 \n");
    printf("NZCV: 1100 \n");
    printf("===========\n");
    printf("Current PC Val: %8x\n", PC);
    printf("IR: %8x\n", IR);
    printf("CPSR: %8x\n", CPSR);
    printf("Next value of the PC: %8x\n", res);
    printf("Expected: %8x\n\n", expected);

    //Testing matching nzcv with 1000
    PC = 0;
    IR = 0x8b000001;
    CPSR = 0x20000000;
    res = update(PC, IR, CPSR);
    expected = 0x00000008;
    printf("Branch || Cond = 1000 \n");
    printf("NZCV: 1000 \n");
    printf("===========\n");
    printf("Current PC Val: %8x\n", PC);
    printf("IR: %8x\n", IR);
    printf("CPSR: %8x\n", CPSR);
    printf("Next value of the PC: %8x\n", res);
    printf("Expected: %8x\n\n", expected);

    //cond-cat-lbit-simm
    //0000-00-11-000000000000000000000000
    return 0;
}