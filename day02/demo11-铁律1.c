#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main(int arg, char *args[])
{
    int i;
    char buf[128] = {0};
    char *p1 = NULL;
    char *p2 = NULL;
    //1、指针指向谁就把谁的地址赋给指针
    //2、不断给指针赋值就是不断的改变指针的指向
    p1 = &buf[0];
    printf("p1:%p \n", p1);
    p1 = &buf[1];
    printf("p1:%p \n", p1);

    p1 = &buf[2];
    printf("p1:%p \n", p1);
    for (i = 0; i < 10; i++)
    {
        p1 = &buf[i];
        printf("p1:%p \n", p1);
        printf("*p1:%d \n", *p1);
    }
    p2 = (char *)malloc(128);
    strcpy(p2, "aaaaa");
    for (i = 0; i < 5; i++)
    {
        printf("%c ", p2[i]);
    }
    char buf1[] = {'a', 'b', 'c'};
    //buf1是一个字符数组不是一个以\0结尾的c风格的字符串
    //strlen()长度不包含\0
    //sizeof是所占空间的大小包含\0
    char buf2[128] = "avb";
    //buf2是一个常量指针
    p1 = buf2; //数组首元素的地址
    printf("hello,world");
    system("pause");
    return 1;
}