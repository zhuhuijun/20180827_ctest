#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main(int arg, char *args[])
{
    int a = 10;
    int *p1 = NULL;
    p1 = &a;
    printf("p1:%p\n", p1);
    printf("&a:%p\n", &a);
    printf("p1:%d\n", *p1);
    int c = 100;
    printf("&c:%p\n", &c);
    p1 = &c;
    printf("p1:%p\n", p1);
    printf("*p1:%d\n", *p1);

    int d = 200;
    printf("&d:%p\n", &d);
    p1 = &d;
    printf("p1:%p\n", p1);
    printf("*p1:%d\n", *p1);
    printf("hello,world");
    system("pause");
    return 1;
}