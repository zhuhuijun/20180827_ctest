#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/**
 * 一段连续内存空间的别名(门牌号)
 * 1、对内存可读可写
 * 2、是通过变量往内存中读写
 * 3、不是向变量读写
 * 内存是由地址编号的，拿到地址就可以修改内存
 * 对内存空间可以重命名吗？
 * 变量的作用域：名称，大小，作用域
 * 内存四区模型
 * 函数调用模型
 * 
 */
int main(int arg, char *args[])
{
    int a;
    int *b;
    a = 10; //直接修改
    printf("a:%d,&a:%d\n", a, &a);
    b = &a;
    *b = 100; //间接修改内存
    printf("a:%d,&a:%d\n", a, &a);
    printf("hello,world!\n");
    system("pause");
    return 1;
}