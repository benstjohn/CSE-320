
/******************************************************************************

  Assume you need to process a 64-bit floating point value as an unsigned
  integer (so that you can use bitwise operators).

  For example:  extract the biased exponent field and the true exponent.

  <prompt> gcc -Wall project06.union.c
  <prompt> a.out

  Real: 24.500000  Hex integer: 4038800000000000  True exponent: 4

  Real: -0.250000  Hex integer: bfd0000000000000  True exponent: -2

******************************************************************************/

#include <stdio.h>

union double_precision {
  double drep;
  unsigned long long int irep;
};

int main()
{
  union double_precision num;
  signed true_exp;

  num.drep = 24.5;

  printf("Real: %f  Hex integer: %016llx  ", num.drep, num.irep);

  true_exp = ((num.irep >> 52) & 0x7ff) - 0x3ff;

  printf("True exponent: %d \n\n", true_exp);

  num.drep = -0.25;

  printf("Real: %f  Hex integer: %016llx  ", num.drep, num.irep);

  true_exp = ((num.irep >> 52) & 0x7ff) - 0x3ff;

  printf("True exponent: %d \n\n", true_exp);

  return 0;
}
