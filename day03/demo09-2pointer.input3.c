#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/****
 * 第三中内存模型自己打造内存空间
 * 
 */
char **getMem(int num)
{
    char **p = NULL;
    int i = 0;
    p = (char **)malloc(sizeof(char *) * num);
    if (p == NULL)
    {
        return NULL;
    }
    for (i = 0; i < num; i++)
    {
        p[i] = (char *)malloc(100 * sizeof(char));
        sprintf(p[i], "%d%d%d", i + 1, i + 1, i + 1);
    }
    return p;
}

void getMem_Free(char **p, int num)
{
    int i = 0;
    for (i = 0; i < num; i++)
    {
        if (p[i] != NULL)
        {
            free(p[i]);
            p[i] = NULL;
        }
    }
    if (p != NULL)
    {
        free(p);
    }
}

void printArr(char **marr, int num)
{
    int i = 0;
    //打印
    for (i = 0; i < num; i++)
    {
        printf("a:%s\n", marr[i]);
        //printf("p:%s\n", *(marr + i));
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
            if (strcmp(marr[i], marr[j]) < 0)
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
    char **p = NULL;
    int num = 5;
    char *tmp = NULL;
    char buf[100] = {0};
    p = getMem(num);
    if (p == NULL)
    {
        printf("malloc is error\n");
        return 0;
    }
    printArr(p, num);
    //交换指针
    sortArr(p, num);
    printf("sort after....\n");
    printArr(p, num);

    //交换内存块
    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (strcmp(p[i], p[j]) > 0)
            {
                strcpy(buf, p[i]);
                strcpy(p[i], p[j]);
                strcpy(p[j], buf);
            }
        }
    }
    printf("sort after....\n");
    printArr(p, num);

    getMem_Free(p, num);
    printf("hello,world");
    system("pause");
    return 1;
}