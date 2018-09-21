#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/***
 * 1、二级指针做函数输入的第一种模型
 * 
 * 
 */
//数组做函数参数退化为指针
void printArr(char **marr, int num)
{
    int i = 0;
    //打印
    for (i = 0; i < num; i++)
    {
        printf("a:%s\n", marr[i]);
        printf("p:%s\n", *(marr + i));
    }
}
void sortArr(char **marr, int num)
{
    int i = 0;
    int j = 0;
    char *tmp = NULL;
    for (i = 0; i < num; i++)
    {
        for (j = i; j < num; j++)
        {
            if (strcmp(marr[i], marr[j]) > 0)
            {
                //改变的是指针的指向
                tmp = marr[i]; //交换的是数组元素  交换的是指针的值
                marr[i] = marr[j];
                marr[j] = tmp;
            }
        }
    }
}
int main(int arg, char *args[])
{
    int i = 0;
    int j = 0;
    int num = 0;
    char *tmp = NULL;
    //数组 数组中的每个元素是指针  指针数组
    char *marr[] = {"123", "abc", "456"};
    num = sizeof(marr) / sizeof(marr[0]);
    printArr(marr, num);
    //排序
    sortArr(marr, num);
    printf("sort after...\n");
    printArr(marr, num);
    printf("hello,world");
    system("pause");
    return 1;
}