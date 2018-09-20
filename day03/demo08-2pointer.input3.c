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
    char **p = NULL;
    int num = 5;
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