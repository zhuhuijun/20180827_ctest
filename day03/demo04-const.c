#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void getMem(const char *p)
{
    p = (char *)1;
    p = (char *)2;
}
//指针变量不能被修改但是指向的内存空间可以修改
void getMem2(char *const p)
{
    p[1] = 'a';
}
void getMem2(const char *const p)
{
    printf("%c\n", p[1]);
}
int main(int arg, char *args[])
{
    //const int a; //一样的
    //int const b;
    //const char *c; //c是一个指向常整形数的指针
    //所指向的内存空间不不能被修改，但是本身可以修改
    //char *const d; //指针变量不能被修改
    char *p = NULL;
    const char *p1 = NULL;
    const int a = 100; //c语言中的const修饰的变量是假的
    {
        int *p3 = &a;
        *p3 = 1000;
        printf("%d\n", a);
    }
    printf("hello,world");
    system("pause");
    return 1;
}