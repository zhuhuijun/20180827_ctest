#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main(int arg, char *args[])
{
    int i = 0;
    //指针数组
    char *p[] = {"abc", "123", "edf", "456"};
    //二维数组
    char p2[3][4] = {"123", "678", "234"};
    //手工二维
    char **p3 = (char **)malloc(3 * sizeof(char *));
    for (i = 0; i < 3; i++)
    {
        p3[i] = (char *)malloc(10 * sizeof(char));
        sprintf(p3[i], "%d%d", i, i);
    }
    printf("hello,world");
    system("pause");
    return 1;
}