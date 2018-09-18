#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/***
 * 1、二级指针做函数输入的第一种模型
 * 
 * 
 */
int main(int arg, char *args[])
{
    char *marr[] = {"123", "abc", "456"};
    printf("hello,world");
    system("pause");
    return 1;
}