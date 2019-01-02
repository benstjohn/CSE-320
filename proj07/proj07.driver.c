// Proj07.driver.c
// Ben St. John
// CSE 320
//#include "/user/cse320/Projects/project07.support.h"
#include "project07.support.h"
#include <stdio.h>
int main()
{
    char test_char[80] = "";
    unsigned int instruction;

    //Testing with invalid leading bits
    instruction = 0x01a00007;
    printf("Testing with invalid leading bits\n");
    printf("Instruction code: %8x\n", instruction);
    decode(instruction, test_char);
    printf("Actual Output: %s\n", test_char);
    printf("Expected Output: ERROR - leading bits are invalid\n\n");

    //Testing with unused bits = 1
    instruction = 0xe1a01107;
    printf("Testing with unused bits = 1\n");
    printf("Instruction code: %8x\n", instruction);
    decode(instruction, test_char);
    printf("Actual Output: %s\n", test_char);
    printf("Expected Output: ERROR - unused bits should be 0\n\n");

    //Testing S bit = 0 where it must be 1
    instruction = 0xe30800a3;
    printf("Testing S bit = 0 where it must be 1\n");
    printf("Instruction code: %8x\n", instruction);
    decode(instruction, test_char);
    printf("Actual Output: %s\n", test_char);
    printf("Expected Output: ERROR - S bit must be 1 for this instruction\n\n");

    //Testing unsued Rd bits = 1 for 'teq'
    instruction = 0xe318f0a3;
    printf("Testing unused Rd bits = 1 for 'teq'\n");
    printf("Instruction code: %8x\n", instruction);
    decode(instruction, test_char);
    printf("Actual Output: %s\n", test_char);
    printf("Expected Output: ERROR - destination bits should be 0\n\n");

    //Testing unused Rn bits = 0 for 'mvn'
    instruction = 0xe1ec1007;
    printf("Testing unused Rn bits = 1 for 'mvn'\n");
    printf("Instruction code: %8x\n", instruction);
    decode(instruction, test_char);
    printf("Actual Output: %s\n", test_char);
    printf("Expected Output: ERROR - Rn bits should be 0\n\n");

    //Testing 'and' operand; I-bit = 0, S-bit = 0
    instruction = 0xe0060007;
    printf("Operand = 'and', I-bit = 0, S-bit = 0\n");
    printf("Instruction code: %8x\n", instruction);
    printf("Instruction code: %8x\n", instruction);
    decode(instruction, test_char);
    printf("Actual Output: %s\n", test_char);
    printf("Expected Output: and  r0, r6, r7\n\n");

    //Testing 'bics' operand; I-bit = 0, S-bit = 1
    instruction = 0xe1d63007;
    printf("Operand = 'bics', I-bit = 0, S-bit = 1\n");
    printf("Instruction code: %8x\n", instruction);
    decode(instruction, test_char);
    printf("Actual Output: %s\n", test_char);
    printf("Expected Output: bics  r3, r6, r7\n\n");

    //Testing 'adds' operand; I-bit = 1, S-bit = 1
    instruction = 0xe29600ff;
    printf("Operand = 'adds', I-bit = 1, S-bit = 1\n");
    printf("Instruction code: %8x\n", instruction);
    decode(instruction, test_char);
    printf("Actual Output: %s\n", test_char);
    printf("Expected Output: adds  r0, r6, #0xff\n\n");

    //Testing 'tst' operand; I-bit = 1, S-bit = 1
    instruction = 0xe31800a3;
    printf("Operand = 'tst', I-bit = 1, S-bit = 1\n");
    printf("Instruction code: %8x\n", instruction);
    decode(instruction, test_char);
    printf("Actual Output: %s\n", test_char);
    printf("Expected Output: tst  r8, #0xa3\n\n");

    //Testing 'cmp' operand; I-bit = 0, S-bit = 1
    instruction = 0xe1520003;
    printf("Operand = 'cmp', I-bit = 0, S-bit = 1\n");
    printf("Instruction code: %8x\n", instruction);
    decode(instruction, test_char);
    printf("Actual Output: %s\n", test_char);
    printf("Expected Output: cmp  r2, r3\n\n");

    //Testing 'mov' operand; I-bit = 0, S-bit = 0
    instruction = 0xe1a01003;
    printf("Operand = 'mov', I-bit = 0, S-bit = 0\n");
    printf("Instruction code: %8x\n", instruction);
    decode(instruction, test_char);
    printf("Actual Output: %s\n", test_char);
    printf("Expected Output: mov  r1, r3\n\n");
}