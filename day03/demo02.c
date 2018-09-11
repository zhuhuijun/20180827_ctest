#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

//去除前后空格
int trimSpce2(char *str)
{
    char *p = str;
    int ret = 0;
    int i = 0, j = 0, ncount = 0;
    if (str == NULL)
    {
        return -1;
    }
    j = strlen(p) - 1;
    while (isspace(p[i]) && p[i] != '\0')
    {
        i++;
    }
    while (isspace(p[j]) && p[j] != '\0')
    {
        j--;
    }
    printf("j:%d\n", j);
    printf("i:%d\n", i);
    ncount = j - i + 1;
    strncpy(str, str + i, ncount);
    p[ncount] = '\0';
    return ret;
}

int main(int arg, char *args[])
{
    char source[1024] = "  abcdef  ";
    printf("source:%s\n", source);
    trimSpce2(source);
    printf("new source:%s\n", source);
    printf("hello,world");
    system("pause");
    return 1;
}