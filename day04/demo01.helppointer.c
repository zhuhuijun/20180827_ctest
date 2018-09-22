#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main(int arg, char *args[])
{
    char *p1 = "aaaa,bbbb,cccc,dddd,eeee";
    char ctm = ',';
    char marr[10][30] = {0};
    int count = 0;
    int i = 0;
    int ret = splitstr(p1, ctm, marr, &count);
    printf("hello,world");
    system("pause");
    return 1;
}

int splitstr(char *old, char split, char target[10][30], int *count)
{
    if (old == NULL || count == NULL)
    {
        return -1;
    }
    return 0;
}