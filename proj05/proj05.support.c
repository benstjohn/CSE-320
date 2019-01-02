#include "/user/cse320/Projects/project05.support.h"
#include <stdio.h>
//Ben St. John
//10-2-18
//CSE 320 Computer Proj05
//Support - main class
int convert(const char ch[], int b, int *conversion)
{
    int hasVal = 0;
    int isNeg = 0;
    int isPos = 1;
    int i = 0;
    *conversion = 0;
    //test if base is 2 through 36
    if (b < 1 || b > 36)
    {
        return 0;
    }

    //until a break or we hit the null ender
    for (i = 0; ch[i] != '\0'; ++i)
    {
        //checking for the different whitespaces
        if (ch[i] == '\n' || ch[i] == '\t' || ch[i] == ' ')
        {
            if (hasVal != 0)
            {
                break;
            }
        }
        else if (ch[i] == '+' || ch[i] == '-') //Checks to see if positive is there
        {
            if (hasVal != 0)
            {
                break;
            }
            else if (ch[i] == '+')
            {
                isPos = 1;
                isNeg = 0;
            }
            else if (ch[i] == '-')
            {
                isPos = 0;
                isNeg = 1;
            }
        }
        else if ((ch[i] >= 'A') && (ch[i] <= 'Z')) //Checks for capital values
        {
            int value = ((ch[i] - 'A') + 10);
            if (value >= b)
            {
                if (hasVal != 0)
                {
                    break;
                }
                return 0;
            }
            *conversion = value + (b * (*conversion));
            hasVal++;
        }
        else if ((ch[i] >= 'a') && (ch[i] <= 'z')) //Checks for lowercase values
        {
            int value = ((ch[i] - 'a') + 10);
            if (value >= b)
            {
                if (hasVal != 0)
                {
                    break;
                }
                return 0;
            }
            *conversion = value + (b * (*conversion));
            hasVal++;
        }
        else if ((ch[i] >= '0') && (ch[i] <= '9')) //Checks for digits
        {
            int value = (ch[i] - '0');
            if (value >= b)
            {
                if (hasVal != 0)
                {
                    break;
                }
                return 0;
            }
            *conversion = value + (b * (*conversion));
            hasVal++;
        }
        else //this is for all other random symbols
        {
            if (hasVal != 0)
            {
                break;
            }
            return 0;
        }
    }

    //this is called when you get a bunch of valid (whitespace) chars that can't convert
    if (hasVal == 0)
    {
        return 0;
    }

    //flips the value if it's negative
    if (isNeg == 1)
    {
        *conversion = 0 - *conversion;
    }
    //final return true
    return 1;
}