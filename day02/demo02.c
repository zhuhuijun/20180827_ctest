#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main01(int arg, char *args[])
{
    char *p1 = NULL;
    //向p1指向的内存空间变量copy数据
    strcpy(p1, "aaaaaaaaaaa");
    printf("hello,world");
    system("pause");
    return 1;
}
//不断改变指针的指向
int main(int arg, char *args[])
{
    int i, j = 0;
    char buf[128];
    char *p1 = NULL;
    char *p2 = NULL;
    p1 = &buf[0];
    for (i = 0; i < 10; i++)
    {
        p1 = &buf[i];
    }

    p2 = (char *)malloc(128);
    strcpy(p2, "abcdefghijg");
    for (i = 0; i < 10; i++)
    {
        p1 = p2 + i;
        printf("%c\n", *p1);
    }
    printf("hello,world");
    system("pause");
    return 1;
}