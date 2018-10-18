#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int getContentLen01(const char *filename, char **buf, int *len)
{
    char *tmp = NULL;
    tmp = (char *)malloc(100 * sizeof(char));
    if (tmp == NULL)
    {
        return -1;
    }
    strcpy(tmp, "aaaaaaaaaaaaaaaaaaaaaaaaaa");
    *len = 10;
    *buf = tmp; //间接赋值
    return 0;
}

int getContentLen02(const char *filename, char *buf, int *len)
{
    char *tmp = NULL;
    tmp = (char *)malloc(100 * sizeof(char));
    if (buf == NULL)
    {
        *len = 10; //第一次调用求长度
    }
    else
    {
        strncpy(buf, "aaaaaaaaaa", 10);
        *len = 10;
    }
    return 0;
}

int main(int arg, char *args[])
{
    //char buf[1024*20];
    const char *filename = "c:/1.txt";
    char *p = NULL;
    int len = 0;

    getContentLen01(filename, &p, &len);

    if (p != NULL)
    {
        free(p);
        p = NULL;
    }

    //第一次调用求长度
    getContentLen02(filename, NULL, &len);

    p = (char *)malloc(len);
    memset(p, 0, len);
    if (p == NULL)
    {
        return 1;
    }

    //第二次调用求内容
    getContentLen02(filename, p, &len);
    printf("%s\n", p);
    if (p != NULL)
    {
        free(p);
        p = NULL;
    }
    printf("hello...\n");
    system("pause");
    return 0;
}