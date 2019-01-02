// Proj06.support.c
// Ben St. John
// CSE 320
#include "/user/cse320/Projects/project06.support.h"
#include <stdio.h>
double add(double a, double b)
{
    //Immediately test special cases
    //checking for not-a-number
    if (a == NAN || b == NAN)
    {
        return NAN;
    }

    //checking for infinity
    if (a == INFINITY || b == INFINITY)
    {
        return INFINITY;
    }

    union double_precision a_num;
    union double_precision b_num;
    union double_precision sum;
    int normalized = 0;
    int isNeg = 0;
    int bothNeg = 0;

    //making the doubles double precision
    a_num.drep = a;
    b_num.drep = b;

    //Extraction of sign
    unsigned int a_sign = (a_num.irep >> 63);
    unsigned int b_sign = (b_num.irep >> 63);

    //Extraction of exponent
    unsigned a_true_exp = ((a_num.irep >> 52) & 0x7ff) - 0x3ff;
    unsigned a_biased = a_true_exp + 0x3ff;

    unsigned b_true_exp = ((b_num.irep >> 52) & 0x7ff) - 0x3ff;
    unsigned b_biased = b_true_exp + 0x3ff;

    //Extraction of significand
    unsigned long long int a_fract = (((a_num.irep & 0x000fffffffffffff) << 12) >> 12);
    unsigned long long int a_sig = a_fract | 0x0010000000000000;

    unsigned long long int b_fract = (((b_num.irep & 0x000fffffffffffff) << 12) >> 12);
    unsigned long long int b_sig = b_fract | 0x0010000000000000;

    //what do the biased exp differ by?
    unsigned long long dif = a_biased - b_biased;
    unsigned long long new_ex = a_biased;

    //checking if a is infinity or nan
    if (a_biased == 0x7ff)
    {
        if (a_sig == 0x0000000000000000)
        {
            return INFINITY;
        }
        else
        {
            return NAN;
        }
    }

    //checking if b is infinity or nan
    if (b_biased == 0x7ff)
    {
        if (b_sig == 0x0010000000000000)
        {
            return INFINITY;
        }
        else
        {
            return NAN;
        }
    }

    //if we get a negative num
    if (a_sign == 1)
    {
        bothNeg++;
        a_sig = -a_sig;
    }
    //if we get a negative num
    if (b_sign == 1)
    {
        bothNeg++;
        b_sig = -b_sig;
    }

    //checking which exponenet is larger than the other
    if (a_biased > b_biased)
    {
        new_ex = a_biased;
        b_sig = b_sig >> dif;
    }
    else
    {
        new_ex = b_biased;
        a_sig = a_sig >> dif;
    }

    unsigned long long int sum_sig = a_sig + b_sig;
    //if sum of significands are negative, flip it

    if ((sum_sig & 0x8000000000000000) == 0x8000000000000000 || bothNeg)
    {
        sum_sig = -sum_sig;
        isNeg = 1;
    }

    //doing that first normalization boii
    if ((sum_sig & 0x0020000000000000) == 0x0020000000000000)
    {
        sum_sig = sum_sig >> 1;
        new_ex = new_ex + 1;
        normalized = 1;
    }

    //doing the other normalization loop
    while (!normalized)
    {
        if (sum_sig == 0x0000000000000000)
        {
            return 0;
        }
        else
        {
            if ((sum_sig & 0x0010000000000000) == 0x0000000000000000)
            {
                sum_sig = sum_sig << 1;
                new_ex = new_ex + 1;
            }
            else
            {
                normalized = 1;
            }
        }
    }

    //pack these boys back together
    unsigned long long int finalsum = ((new_ex & 0x00000000000007ff) << 52) | (sum_sig & 0x000fffffffffffff);
    //make it negative if we have to
    if (isNeg || bothNeg)
    {
        finalsum = ((finalsum) | 0x8000000000000000);
    }
    //this is how we switch back to a double
    sum.irep = finalsum;
    return sum.drep;
}
