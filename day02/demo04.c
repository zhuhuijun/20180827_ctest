#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
void change(char **p)
{
    *p = (char *)1000;
}
int main(int arg, char *args[])
{
    char *p1 = NULL;
    p1 = (char *)malloc(100);
    strcpy(p1, "aaa");
    printf("p1:%s\n", p1);
    if (p1 != NULL)
    {
        free(p1);
        p1 = NULL;
    }
    char **p2 = NULL;
    p1 = (char *)0x11;
    printf("p1:%d\n", p1);
    p2 = (char **)0x22;
    //直接修改p1的值
    p1 = (char *)0x111;
    printf("p1:%d\n", p1);
    //间接修改p1的值p2是p1的地址
    p2 = &p1;
    //间接修改
    *p2 = (char *)100;

    printf("p1:%d\n", p1);
    change(p2);
    change(&p1);
    printf("p1:%d\n", p1);

    printf("hello,world");
    system("pause");
    return 1;
}