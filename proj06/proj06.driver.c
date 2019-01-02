// Proj06.driver.c
// Ben St. John
// CSE 320
#include "/user/cse320/Projects/project06.support.h"
#include <stdio.h>

int main()
{
    union double_precision sum, cor;
    double a = 0.5, b = 0.5;
    cor.drep = a + b;
    sum.drep = add(a, b);
    printf("Test case with two small digits\n");
    printf("Given numbers: %f, %f\n", a, b);
    printf("Expected: %f\n", cor.drep);
    printf("Actual: %f\n\n", sum.drep);

    a = 8.0, b = 9.0;
    cor.drep = a + b;
    sum.drep = add(a, b);
    printf("Test case with two positive vals\n");
    printf("Given numbers: %f, %f\n", a, b);
    printf("Expected: %f\n", cor.drep);
    printf("Actual: %f\n\n", sum.drep);

    a = -12.0, b = -1.0;
    cor.drep = a + b;
    sum.drep = add(a, b);
    printf("Test case with two negative vals\n");
    printf("Given numbers: %f, %f\n", a, b);
    printf("Expected: %f\n", cor.drep);
    printf("Actual: %f\n\n", sum.drep);

    a = NAN, b = 9.0;
    cor.drep = a + b;
    sum.drep = add(a, b);
    printf("Test case with NAN\n");
    printf("Given numbers: %f, %f\n", a, b);
    printf("Expected: %f\n", cor.drep);
    printf("Actual: %f\n\n", sum.drep);

    a = 8.0, b = INFINITY;
    cor.drep = a + b;
    sum.drep = add(a, b);
    printf("Test case with INFINITY\n");
    printf("Given numbers: %f, %f\n", a, b);
    printf("Expected: %f\n", cor.drep);
    printf("Actual: %f\n\n", sum.drep);

    a = 2.25, b = 3.25;
    cor.drep = a + b;
    sum.drep = add(a, b);
    printf("Test case with positive fractions\n");
    printf("Given numbers: %f, %f\n", a, b);
    printf("Expected: %f\n", cor.drep);
    printf("Actual: %f\n\n", sum.drep);

    a = -8.75, b = 0.50;
    cor.drep = a + b;
    sum.drep = add(a, b);
    printf("Test case with one pos and one neg\n");
    printf("Given numbers: %f, %f\n", a, b);
    printf("Expected: %f\n", cor.drep);
    printf("Actual: %f\n\n", sum.drep);

    a = -8.75, b = 8.75;
    cor.drep = a + b;
    sum.drep = add(a, b);
    printf("Test case with sum equals zero\n");
    printf("Given numbers: %f, %f\n", a, b);
    printf("Expected: %f\n", cor.drep);
    printf("Actual: %f\n\n", sum.drep);
}
