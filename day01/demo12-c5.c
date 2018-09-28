#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/**
 * 测栈的开口方向
 * debug:b的地址小，说明开口是向下
 * release:b的地址大
 * 不管栈的开口方向是向上还是向下
 * ，buf+1的生长方向永远是向上的
 * 静态联编的时候buf的地址已经定义好了
 */
int main(int arg, char *args[])
{
    int a;
    int b;
    char buf[128];
    printf("&a:%d,&b:%d", &a, &b);
    printf("hello,world");
    system("pause");
    return 1;
}