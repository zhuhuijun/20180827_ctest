#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int getConentLen1(const char *filename, char **buf, int *len1)
{
    char *tmp = NULL;
    tmp = (char *)malloc(100 * sizeof(char));
    if (NULL == tmp)
    {
        return -1;
    }
    strcpy(tmp, "aaaaaaaaaa");
    *len1 = 10;
    *buf = tmp;
    return 0;
}
int getConentLen2(const char *filename, char *buf, int *len1)
{
    if (NULL == buf)
    {
        *len1 = 10; //第一次调用求长度
    }
    else
    {
        //\0要留着
        strncpy(buf, "aaaaaaaaa", 10);
    }
    return 0;
}
void freeBuf(char **buf)
{
    char *tmp = NULL;
    tmp = *buf;
    if (tmp != NULL)
    {
        free(tmp);
    }
    *buf = NULL;
}
int main01(int arg, char *args[])
{
    const char *filename = "d:/1.txt";
    char *buf = NULL;
    int len;
    getConentLen1(filename, &buf, &len);
    printf("%s\n", buf);
    freeBuf(&buf);

    printf("hello,world");
    system("pause");
    return 1;
}

int main(int arg, char *args[])
{
    const char *filename = "d:/1.txt";
    char *buf = NULL;
    int len;
    getConentLen2(filename, NULL, &len);
    printf("len:%d\n", len);
    buf = (char *)malloc(len);
    getConentLen2(filename, buf, &len);
    printf("%s\n", buf);
    printf("hello,world");
    system("pause");
    return 1;
}