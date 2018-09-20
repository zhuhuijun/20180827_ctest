#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/****
 * 第三中内存模型自己打造内存空间
 * 
 */
int main(int arg, char *args[])
{
    int i = 0;
    int j = 0;
    char **p = NULL;
    int num = 5;
    char *tmp = NULL;
    char buf[100] = {0};
    p = (char **)malloc(sizeof(char *) * num);
    for (i = 0; i < num; i++)
    {
        p[i] = (char *)malloc(100 * sizeof(char));
        sprintf(p[i], "%d%d%d", i + 1, i + 1, i + 1);
    }
    for (i = 0; i < num; i++)
    {
        printf("p[%d]:%s\n", i, p[i]);
    }
    //交换指针
    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (strcmp(p[i], p[j]) < 0)
            {
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
        }
    }
    printf("sort after....\n");
    for (i = 0; i < num; i++)
    {
        printf("p[%d]:%s\n", i, p[i]);
    }
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
    for (i = 0; i < num; i++)
    {
        printf("p[%d]:%s\n", i, p[i]);
    }
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
        p = NULL;
    }
    printf("hello,world");
    system("pause");
    return 1;
}