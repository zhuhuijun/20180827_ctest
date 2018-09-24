#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/****
 * 
 * 1、定义数组指针类型的第二种方法
 */
int main01(int arg, char *args[])
{
    int i = 0;
    typedef int(*pArr)[5];
    pArr pa; //告诉编译器分配指针变量
    //定义数组
    int c[5] = {0};
    pa = &c; //指针变量指向整个数组
    for (i = 0; i < 5; i++)
    {
        (*pa)[i] = i + 1;
    }
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", (*pa)[i]);
    }
    printf("hello,world");
    system("pause");
    return 1;
}
//第三种定义数组指针方法
//前两种通过类型定义变量
int main(int arg, char *args[])
{
    int i;
    // char *marr[] = {"123", "abc", "456"};
    int(*pMyArr)[5]; //直接定义一个指向数组的指针变量
    int c[5] = {0};
    pMyArr = &c; //指针变量指向整个数组
    for (i = 0; i < 5; i++)
    {
        (*pMyArr)[i] = i + 1;
    }
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", (*pMyArr)[i]);
    }
    printf("hello,world");
    system("pause");
    return 1;
}