#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>
int main01(int arg, char *args[])
{
    char *source = "            abcdefg                   ";
    int i, j, ncount;
    ncount = 0;
    i = 0;
    j = strlen(source) - 1;
    while (isspace(source[i]) && source[i] != '\0')
    {
        i++;
    }
    while (isspace(source[j]) && source[j] != '\0')
    {
        j--;
    }
    ncount = j - i + 1;
    printf("ncount:%d\n", ncount);

    printf("hello,world");
    system("pause");
    return 1;
}
/**
 * 
 * 获得字符串的长度
 */
int getCount(char *p, int *count)
{
    char *source = NULL;
    int ret = 0;
    int i = 0, j = 0, ncount = 0;
    if (p == NULL || count == NULL)
    {
        return -1;
    }
    source = p;
    j = strlen(source) - 1;
    while (isspace(source[i]) && source[i] != '\0')
    {
        i++;
    }
    while (isspace(source[j]) && source[j] != '\0')
    {
        j--;
    }
    printf("j=%d\n", j);
    printf("i=%d\n", i);
    ncount = j - i + 1;
    *count = ncount;
    return ret;
}
//去除前后空格
int trimSpce(char *p, char *out)
{
    char *source = NULL;
    int ret = 0;
    int i = 0, j = 0, ncount = 0;
    if (p == NULL || out == NULL)
    {
        return -1;
    }
    source = p;
    j = strlen(source) - 1;
    while (isspace(source[i]) && source[i] != '\0')
    {
        i++;
    }
    while (isspace(source[j]) && source[j] != '\0')
    {
        j--;
    }
    ncount = j - i + 1;
    strncpy(out, p + i, ncount);
    out[ncount] = '\0';
    return ret;
}

int main(int arg, char *args[])
{
    char *source = "  abcdef  ";
    int ncount = 0;
    int ret = getCount(source, &ncount);
    if (ret != 0)
    {
        printf("some error \n");
        return -1;
    }
    printf("ncount:%d\n", ncount);
    char bufnew[1024] = {0};
    trimSpce(source, bufnew);
    printf("newstr:%s\n", bufnew);
    printf("hello,world");
    system("pause");
    return 1;
}