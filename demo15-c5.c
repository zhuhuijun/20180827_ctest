#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/***
 * 指针是一种数据类型这些参数怎么看?
 * 站在编译器的角度来看
 * 形参做函数参数，参数有多级指针，站在编译器的角度只需要分配4个字节的内存(32位平台)
 * 当使用指针时我们才会关心指针所指的内存时一维还是二维的
 * 指针也是一种数据类型，指针的数据类型指的时它指向的内存空间的数据类型
 * 指针的步长根据它所指的内存空间的数据类型来确定
 */
int getAbc1(char *p1);
int getAbc2(char **p2);
int getAbc3(char ***p3);
int getAbc4(char (*p4)[30]);
int getAbc5(char p5[10][30]);
int main(int arg, char *args[])
{
    printf("hello,world");
    system("pause");
    return 1;
}