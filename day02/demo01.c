#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//野指针产生的原因
/***
 * 
 * 1、定义变量时职位NULL
 * 2、释放指向的空间地址时置为NULL
 * 
 */
int main(int arg, char *args[])
{
    char *p1 = NULL;
    p1 = (char *)malloc(100);
    if (p1 == NULL)
    {
        return 0;
    }
    strcpy(p1, "aaaaaaaaaa");
    printf("p1:%s", p1);
    if (p1 != NULL)
    {
        //释放了指针所指向的内存空间
        //但是指针本身没有置为NULL
        free(p1);
        p1 = NULL;
    }
    //
    if (p1 != NULL)
    {
        free(p1);
    }

    printf("hello,world");
    system("pause");
    return 1;
}