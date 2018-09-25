#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void myprint(int *array, int num)
{
    int i = 0;
    for (i = 0; i < num; i++)
    {
        printf("%d ", array[i]);
    }
}
int main(int arg, char *args[])
{
    int a[3][5];
    int i, j, tmp = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            a[i][j] = tmp++;
        }
    }
    //把二维数组当一维数组打印证明是线性存储的，因为是15个元素
    myprint((int *)a, 15);
    printf("hello,world");
    system("pause");
    return 1;
}