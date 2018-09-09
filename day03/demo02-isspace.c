#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>
int main(int arg, char *args[])
{
    char *p = 'c';
    isspace(p);
    printf("hello,world");
    system("pause");
    return 1;
}