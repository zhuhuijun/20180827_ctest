#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/**
 * 1、c语言的字符串是以\0结尾的字符串
 * 2、c语言没有字符串类型,通过字符数组来模拟字符串
 * 3、字符串可以在栈，堆，全局区
 * 
 * 
 */
//字符数组的初始化
int main01(int arg, char *args[])
{
    //1、指定长度后面的自动补0
    char buf[100] = {'a', 'b', 'c', 'd'};
    printf("buf:%s\n", buf);
    printf("buf[88]:%d\n", buf[88]);
    //2、不指定长度,是一个数组，不是以0结尾的字符串
    char buf1[] = {'a', 'b', 'c', 'd'};
    printf("hello,world");
    system("pause");
    return 1;
}
//用字符串初始化字符数组
int main02(int arg, char *args[])
{
    char buf3[] = "abcd"; //作为字符数组长度是5，作为字符串长度是4
    printf("buf字符串长度:%d\n", strlen(buf3));
    //数组是一种数据类型，固定大小内存块的别名
    //siteof是操作符
    printf("buf数组长度:%d\n", sizeof(buf3));
    printf("hello,world");
    system("pause");
    return 1;
}
//通过数组下标  指针
int main(int arg, char *args[])
{
    int i = 0;
    char buf[128] = "abfgf";
    char *p = NULL;
    for (i = 0; i < strlen(buf); i++)
    {
        printf("%c\n", buf[i]);
    }
    //指针
    printf("-------------------------\n");
    p = buf; //buf代表数组首元素的地址
    while (*p != '\0')
    {
        printf("%c\n", *p);
        p++;
    }
    printf("hello,world");
    system("pause");
    return 1;
}