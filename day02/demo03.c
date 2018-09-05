#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/****************************************
 *间接赋值是指针存在的最大意义 
 * 用指针做函数参数
 * 参数的副本机制
 * 
 * 
 * 
 ****************************************/
void getFileLen(int *p)
{
    *p = 400;
}

int getFileLen(int *p)
{
    a = 400;
    return a;
}
int main(int arg, char *args[])
{
    int a = 10;
    int *p = NULL;
    a = 20; //直接修改
    p = &a;
    *p = 200; //间接赋值p的值是a的地址
    //*就是一把钥匙,通过地址找到一块内存空间,间接修改了a的值
    getFileLen(p);
    {
        *p = 4000;
        printf("a:%d", a);
    }
    printf("a:%d\n", a);
    printf("hello,world");
    system("pause");
    return 1;
}