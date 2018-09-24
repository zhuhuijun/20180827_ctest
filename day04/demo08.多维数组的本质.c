#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main(int arg, char *args[])
{
    int a[3][5], i = 0;
    int j = 0;
    int tmp = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            a[i][j] = tmp++;
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf(" %2d ", a[i][j]);
        }
        printf("\n");
    }
    //a多维数组名 a+1
    printf("a:%d,a+1:%d\n", a, a + 1); //5*4个字节
    //相当于是一个数组指针
    printf("&a:%d,&a+1:%d\n", &a, &a + 1);
    //定义过一个指向数组的指针变量
    int(*PArr)[5]; //告诉编译器分配4个字节的指针变量
    PArr = a;
    //多维数组和指向数组的指针变量是一致的
    //多维数组名的本质就是一个数组指针
    //每次就跳动维数的长度
    //(a+i) 代表第i行的整个地址 二级指针
    //*(a+i) 代表一级指针，代表第i行首元素的地址
    //*(a+i) +j 代表===&a[i][j]
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf(" %2d ", PArr[i][j]);
        }
        printf("\n");
    }
    printf("hello,world");
    system("pause");
    return 1;
}