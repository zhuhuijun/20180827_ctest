#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/******************
 * 定义数组指针的方法
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
typedef int(MYINT5)[5]; //int[5]
int main(int arg, char *args[])
{
    //指针数组
    char *myarr[] = {"abc", "123", "bcd", "456"};
    //数组指针,用一个指针来指向一个数组
    MYINT5 marr5;   //用类型定义变量
    MYINT5 *pmarr5; //定义一个指针变量，整个变量指向一个指针
    {
        int a = 0;
        int *p = NULL;
        p = &a;
    }
    {
        int myarr2[5]; //相当于一级指针
        int i = 0;
        for (i = 0; i < 5; i++)
        {
            myarr2[i] = i + 1;
        }
        pmarr5 = &myarr2;
        for (i = 0; i < 5; i++)
        {
            printf("np:%d\n", myarr2[i]);
            printf("p:%d\n", (*pmarr5)[i]);
        }
    }

    printf("hello,world");
    system("pause");
    return 1;
}
