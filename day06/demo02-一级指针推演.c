#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void change(int *p)
{
    *p = -1;
}
int main(int arg, char *args[])
{
    int a = 10;
    int *p;
    a = 100; //直接赋值
    p = &a;
    *p = 1000;
    printf("a = %d\n", a);
    {
        *p = -1;
    }
    printf("hello,world");
    system("pause");
    return 1;
}