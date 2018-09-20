#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//数组做函数参数退化为指针
//和第一种模型的内存模型不一样 ，指针的步长不一样，指针所指向的内存空间的类型不一样
//void printArr(char **marr, int num)
void printArr(char marr[][30], int num)
{
    int i = 0;
    //打印
    for (i = 0; i < num; i++)
    {
        printf("a:%s\n", marr[i]);
        printf("p:%s\n", *(marr + i));
    }
}
//排序
void sortarr(char marr[][30], int num)
{
    int i;
    int j = 0;
    char tmpbuf[30] = {0};
    for (i = 0; i < num; i++)
    {
        for (j = i; j < num; j++)
        {
            if (strcmp(marr[i], marr[j]) > 0)
            {
                strcpy(tmpbuf, marr[i]); //交换的内存块
                strcpy(marr[i], marr[j]);
                strcpy(marr[j], tmpbuf);
            }
        }
    }
}
int main(int arg, char *args[])
{
    int i;
    int j = 0;
    int num = 0;
    char tmpbuf[30] = {0};
    char marr[10][30] = {"aaaa", "1111", "22", "2222"};
    num = 4;
    printArr(marr, num);
    sortarr(marr, num);
    printf("sort after\n");
    printArr(marr, num);
    printf("hello,world");
    system("pause");
    return 1;
}