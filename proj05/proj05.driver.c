#include "/user/cse320/Projects/project05.support.h"
#include <stdio.h>
//Ben St. John
//10-2-18
//CSE 320 Computer Proj05
//Driver - test class
int main()
{

    //testing all invalid characters (should return false)
    char test_0[] = "asdf";
    int b_0 = 2;
    int num_0 = 0;
    int T0 = convert(&test_0[0], b_0, &num_0);
    if (T0 == 0)
    {
        printf("Testing invalid case: %s with base %d\n", test_0, b_0);
        printf("Convert function returned %d, expected was: 0\n\n", T0);
    }

    //testing with only whitespace and base 31
    char test_1[] = "\n    \t   \n";
    int b_1 = 31;
    int num_1 = 0;
    int T1 = convert(&test_1[0], b_1, &num_1);
    if (T1 == 1)
    {
        printf("Testing invalid case with only whitespace\n");
        printf("Convert function returned %d, expected was: 0\n\n", T1);
    }

    //leading whitespace with valid values
    char test_2[] = " \t    1001";
    int b_2 = 2;
    int num_2 = 0;
    int T2 = convert(&test_2[0], b_2, &num_2);
    if (T2 == 1)
    {
        printf("Testing valid case with leading whitespace\n");
        printf("Convert function returned %d, expected was: 1\n", T2);
        printf("Input: %s\n", test_2);
        printf("Base: %d\n", b_2);
        printf("Expected Output: 9\n");
        printf("Decimal Output: %d\n", num_2); //should be 9
        printf("Hex: %08x\n\n", num_2);
    }

    //test with both positive and negative and base 16
    char test_3[] = "  +abcd-";
    int b_3 = 16;
    int num_3 = 0;
    int T3 = convert(&test_3[0], b_3, &num_3);
    if (T3 == 1)
    {
        printf("Testing valid case with positive +\n");
        printf("Convert function returned %d, expected was: 1\n", T3);
        printf("Input: %s\n", test_3);
        printf("Base: %d\n", b_3);
        printf("Expected Output: 43981\n");
        printf("Decimal Output: %d\n", num_3); //should be 43981
        printf("Hex: %08x\n\n", num_3);
    }

    //test with both positive and negative and base 32
    char test_4[] = "-asdf";
    int b_4 = 32;
    int num_4 = 0;
    int T4 = convert(&test_4[0], b_4, &num_4);
    if (T4 == 1)
    {
        printf("Testing valid case with - and new base\n");
        printf("Convert function returned %d, expected was: 1\n", T4);
        printf("Input: %s\n", test_4);
        printf("Base: %d\n", b_4);
        printf("Expected Output: -356783\n");
        printf("Decimal Output: %d\n", num_4); //should be -356783
        printf("Hex: %08x\n\n", num_4);
    }

    //test with capital letters and lowercase
    char test_5[] = "AbCdEf";
    int b_5 = 30;
    int num_5 = 0;
    int T5 = convert(&test_5[0], b_5, &num_5);
    if (T5 == 1)
    {
        printf("Testing valid case with capital and lowercase\n");
        printf("Convert function returned %d, expected was: 1\n", T5);
        printf("Input: %s\n", test_5);
        printf("Base: %d\n", b_5);
        printf("Expected Output: 252246135\n");
        printf("Decimal Output: %d\n", num_5); //should be 252246135
        printf("Hex: %08x\n\n", num_5);
    }

    //testing with normal thing and symbols that are invalid
    char test_6[] = "00FG&^*";
    int b_6 = 17;
    int num_6 = 0;
    int T6 = convert(&test_6[0], b_6, &num_6);
    if (T6 == 1)
    {
        printf("Testing valid case with symbols at the end\n");
        printf("Convert function returned %d, expected was: 1\n", T6);
        printf("Input: %s\n", test_6);
        printf("Base: %d\n", b_6);
        printf("Expected Output: 271\n");
        printf("Decimal Output: %d\n", num_6); //should be 271
        printf("Hex: %08x\n\n", num_6);
    }

    //testing with only symbols that can't be recognized
    char test_7[] = "&^*@#$";
    int b_7 = 17;
    int num_7 = 0;
    int T7 = convert(&test_7[0], b_7, &num_7);
    if (T7 == 1)
    {
        printf("Testing invalid case with only symbols (non-alphanum)\n");
        printf("Convert function returned %d, expected was: 0\n\n", T7);
    }

    //testing with invalid base
    char test_8[] = "110";
    int b_8 = 42;
    int num_8 = 0;
    int T8 = convert(&test_8[0], b_8, &num_8);
    if (T8 == 1)
    {
        printf("Testing invalid case with base out of range.\n");
        printf("Base: %d\n", b_8);
        printf("Convert function returned %d, expected was: 0\n\n", T8);
    }

    //testing binary conversion to decimal and negative
    char test_9[] = "-1111F";
    int b_9 = 2;
    int num_9 = 0;
    int T9 = convert(&test_9[0], b_9, &num_9);
    if (T9 == 1)
    {
        printf("Testing valid case with negative binary\n");
        printf("Convert function returned %d, expected was: 1\n", T9);
        printf("Input: %s\n", test_9);
        printf("Base: %d\n", b_9);
        printf("Expected Output: -15\n");
        printf("Decimal Output: %d\n", num_9); //should be -15
        printf("Hex: %08x\n\n", num_9);
    }

    //testing octal conversion to decimal and symbol
    char test_10[] = "7654&**";
    int b_10 = 8;
    int num_10 = 0;
    int T10 = convert(&test_10[0], b_10, &num_10);
    if (T10 == 1)
    {
        printf("Testing valid case with base 8 and symbols\n");
        printf("Convert function returned %d, expected was: 1\n", T10);
        printf("Input: %s\n", test_10);
        printf("Base: %d\n", b_10);
        printf("Expected Output: 4012\n");
        printf("Decimal Output: %d\n", num_10); //should be 4012
        printf("Hex: %08x\n\n", num_10);
    }

    //testing hex conversion to Decimal and whitespace (different case)
    char test_11[] = "   \tAFAb";
    int b_11 = 16;
    int num_11 = 0;
    int T11 = convert(&test_11[0], b_11, &num_11);
    if (T11 == 1)
    {
        printf("Testing valid case with hex conversion and whitespace\n");
        printf("Convert function returned %d, expected was: 1\n", T11);
        printf("Input: %s\n", test_11);
        printf("Base: %d\n", b_11);
        printf("Expected Output: 44971\n");
        printf("Decimal Output: %d\n", num_11); //should be 44971
        printf("Hex: %08x\n\n", num_11);
    }
}
