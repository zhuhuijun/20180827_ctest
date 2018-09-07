#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main(int arg, char *args[])
{
    //全局区的字符串，定义并初始化，还有\0
    char buf[20] = "aaaa";
    //全局区的字符串，在栈区
    char buf2[] = "bbbb";
    char *p1 = "cccc";
    ///ddd在堆区
    char *p2 = (char *)malloc(100);
    strcpy(p2, "dddd");
    printf("hello,world");
    system("pause");
    return 1;
}