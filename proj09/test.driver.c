
/********************************************************************
  Example #25 -- ARM data organization (arrays of records)
********************************************************************/

#include <stdio.h>
#include "/user/cse320/lib/memlib.h"

#define MAX 8

struct student
{
    char name[12];
    short exam1;
    short exam2;
};

void print_all(struct student *, int);

int main()
{
    struct student list[MAX];
    int i;

    for (i = 0; i < MAX; i++)
    {
        scanf("%s %hd %hd", &list[i].name[0], &list[i].exam1, &list[i].exam2);
    }
    print_all(&list[0], MAX);

    display(&list[0], MAX * 16, 16);
}
