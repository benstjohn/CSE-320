
/********************************************************************
 * Ben St. John
 * Project 9
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "/user/cse320/Projects/project09.support.h"

int main()
{
  //Setting params
  int param0 = 2;
  int param1 = 10;
  int param2 = 5;
  int param3 = -6;
  int param4 = -3;
  int param5 = 0;
  int param6 = 0x7fffffff;
  int param7 = 0x260;
  int param8 = 0xffffffff;

  //First run through of negate with positive
  int result = negate(param1);
  int expected = -1 * param1;
  printf("Function: Negate\n");
  printf("Param(s): %d\n", param1);
  printf("Expected: %d\n", expected);
  printf("Result: %d\n\n", result);

  //Second run through negate with negative
  result = negate(param3);
  expected = -1 * param3;
  printf("Function: Negate\n");
  printf("Param(s): %d\n", param3);
  printf("Expected: %d\n", expected);
  printf("Result: %d\n\n", result);

  //Third run through negate with 0
  result = negate(param5);
  expected = -1 * param5;
  printf("Function: Negate\n");
  printf("Param(s): %d\n", param5);
  printf("Expected: %d\n", expected);
  printf("Result: %d\n\n", result);

  //First run through absolute with 10
  result = absolute(param2);
  expected = abs(param2);
  printf("Function: Absolute\n");
  printf("Param(s): %d\n", param2);
  printf("Expected: %d\n", expected);
  printf("Result: %d\n\n", result);

  //Second run through absolute with -3
  result = absolute(param4);
  expected = abs(param4);
  printf("Function: Absolute\n");
  printf("Param(s): %d\n", param4);
  printf("Expected: %d\n", expected);
  printf("Result: %d\n\n", result);

  //Adding negative and positive
  result = add(param2, param3);
  expected = param2 + param3;
  printf("Function: Add\n");
  printf("Param(s): %d, %d\n", param2, param3);
  printf("Expected: %d\n", expected);
  printf("Result: %d\n\n", result);

  //Adding negative and negative
  result = add(param3, param4);
  expected = param3 + param4;
  printf("Function: Add\n");
  printf("Param(s): %d, %d\n", param3, param4);
  printf("Expected: %d\n", expected);
  printf("Result: %d\n\n", result);

  //Adding overflow
  result = add(param6, param7);
  printf("Function: Add\n");
  printf("Param(s): %d, %d\n", param6, param7);
  printf("Expected: 80000000");
  printf("Result: %8x\n", result);

  //Subtracting positive and negative
  result = sub(param2, param3);
  expected = param2 - param3;
  printf("Function: Subtract\n");
  printf("Param(s): %d, %d\n", param2, param3);
  printf("Expected: %d\n", expected);
  printf("Result: %d\n\n", result);

  //Subtracting positive and positive
  result = sub(param1, param2);
  expected = param1 - param2;
  printf("Function: Subtract\n");
  printf("Param(s): %d, %d\n", param1, param2);
  printf("Expected: %d\n", expected);
  printf("Result: %d\n\n", result);

  //Subtracting overflow
  result = sub(param6, param8);
  printf("Function: Subtract\n");
  printf("Param(s): %d, %d\n", param6, param8);
  printf("Expected: 80000000\n");
  printf("Result: %8x\n\n", result);

  //Multiply positive and negative
  result = mul(param2, param3);
  expected = param2 * param3;
  printf("Function: Multiply\n");
  printf("Param(s): %d, %d\n", param2, param3);
  printf("Expected: %d\n", expected);
  printf("Result: %d\n\n", result);

  //Multiply by 0
  result = mul(param4, param5);
  expected = param4 * param5;
  printf("Function: Multiply\n");
  printf("Param(s): %d, %d\n", param4, param5);
  printf("Expected: %d\n", expected);
  printf("Result: %d\n\n", result);

  //Multiply overflow
  result = mul(param6, param7);
  printf("Function: Multiply\n");
  printf("Param(s): %d, %d\n", param6, param7);
  printf("Expected: 80000000\n");
  printf("Result: %8x\n\n", result);

  //Divide positive by positive
  result = divide(param1, param2);
  expected = param1 / param2;
  printf("Function: Divide\n");
  printf("Param(s): %d, %d\n", param1, param2);
  printf("Expected: %d\n", expected);
  printf("Result: %d\n\n", result);

  //Divide by 0
  result = divide(param3, param5);
  printf("Function: Divide\n");
  printf("Param(s): %d, %d\n", param3, param5);
  printf("Expected: 80000000\n");
  printf("Result: %8x\n\n", result);

  //Power by 0
  result = power(param0, param5);
  expected = 1;
  printf("Function: Power\n");
  printf("Param(s): %d, %d\n", param0, param5);
  printf("Expected: %d\n", expected);
  printf("Result: %d\n\n", result);

  //Power 2^5
  result = power(param0, param2);
  expected = param0 * param0 * param0 * param0 * param0;
  printf("Function: Power\n");
  printf("Param(s): %d, %d\n", param0, param2);
  printf("Expected: %d\n", expected);
  printf("Result: %d\n\n", result);

  //Power Negative Exponenet
  result = power(param2, param3);
  printf("Function: Power\n");
  printf("Param(s): %d, %d\n", param2, param3);
  printf("Expected: 80000000\n");
  printf("Result: %8x\n\n", result);

  //Power Overflow
  result = power(param6, param7);
  printf("Function: Power\n");
  printf("Param(s): %d, %d\n", param6, param7);
  printf("Expected: 80000000\n");
  printf("Result: %8x\n\n", result);

  //Factorial 5
  result = factorial(param2);
  expected = 5 * 4 * 3 * 2 * 1;
  printf("Function: Factorial\n");
  printf("Param(s): %d\n", param2);
  printf("Expected: %d\n", expected);
  printf("Result: %d\n\n", result);

  //Factorial -3
  result = factorial(param4);
  printf("Function: Factorial\n");
  printf("Param(s): %d\n", param4);
  printf("Expected: 80000000\n");
  printf("Result: %8x\n\n", result);

  //Factorial 0
  result = factorial(param5);
  expected = 1;
  printf("Function: Factorial\n");
  printf("Param(s): %d\n", param5);
  printf("Expected: %d\n", expected);
  printf("Result: %d\n\n", result);

  //Factorial overflow
  result = factorial(param6);
  printf("Function: Factorial\n");
  printf("Param(s): %d\n", param6);
  printf("Expected: 80000000\n");
  printf("Result: %8x\n", result);
}
