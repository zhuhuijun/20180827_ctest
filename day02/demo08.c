#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main(int arg, char *args[])
{
    char buf[20] = "aaaa";
    char buf2[] = "bbbb";
    char *p1 = "cccc";
    char *p2 = (char *)malloc(100);
    strcpy(p2, "dddd");
    printf("hello,world");
    system("pause");
    return 1;
}