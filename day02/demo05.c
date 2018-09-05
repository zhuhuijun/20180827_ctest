#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int GetMem3(char **p1, int *len1, char **p2, int *len2)
{
    int ret = 0;
    char *tmp1 = (char *)malloc(100);
    strcpy(tmp1, "123456");
    *len1 = strlen(tmp1);

    char *tmp2 = (char *)malloc(100);
    strcpy(tmp2, "abcdef");
    *len2 = strlen(tmp2);

    *p1 = tmp1;
    *p2 = tmp2;
    return ret;
}
int main(int arg, char *args[])
{
    char *p1 = NULL;
    int len1 = 0;
    char *p2 = NULL;
    int len2 = 0;
    int ret = GetMem3(&p1, &len1, &p2, &len2);
    if (ret != 0)
    {
        printf("some error\n");
        return ret;
    }
    printf("p1:%s\n", p1);
    printf("p2:%s\n", p2);
    if (p1 != NULL)
    {
        free(p1);
        p1 = NULL;
    }
    if (p2 != NULL)
    {
        free(p2);
        p2 = NULL;
    }
    printf("hello,world");
    system("pause");
    return 1;
}