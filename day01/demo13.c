#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/**
 * 指针也是一种变量，占用内存空间，用来保存变量的地址
 * 指针变量占用内存空间的大小
 * 2、*p操作指针
 * 在指针声明时*号表示所声明的变量为指针
 * 在指针使用时*号表示操作指针所指向的内存空间中的值
 * *p相当于通过地址（p变量的值）找到一块内存，然后操作内存
 * *p放在等号的左边赋值
 * *p放在等号的右边取值
 * 不断的给指针赋值，就是相当于不停的改变指针的指向
 * 
 * 
 */
int main(int arg, char *args[])
{
    int a = 10;
    int *p1 = NULL; //告诉编译器分配4个字节的内存空间
    p1 = &a;
    *p1 = 100; //间接修改a的值
    printf("a:%d,p1:%d", sizeof(a), sizeof(p1));
    int c = 0;
    c = *p1;
    printf("c:%d", c);
    char *p4 = NULL;
    p4 = (char *)malloc(sizeof(char) * 100);

    printf("hello,world");
    system("pause");
    return 1;
}