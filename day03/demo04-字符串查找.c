#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

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
/*=======================================================
*1、键值对
*"key1"="aa"
*"key2             "="           fkkfs"
*"key3             "="           fkkfs"
*"key4             "="           fkkfs"
*=======================================================*/
int getKeyByValue(char *kvbuf, char *kbuf, char *vbuf)
{
    //1、查找字串在母串中
    char *p = NULL;
    p = kvbuf;
    p = strstr(p, kbuf);
    if (p == NULL)
    {
        printf("no found key\n");
        return -1;
    }
    //让辅助指针变量重新初始化
    p = p + strlen(kbuf);
    //2、有没有等号
    p = strstr(p, "=");
    if (p == NULL)
    {
        printf("no found =\n");
        return -2;
    }
    //让辅助指针变量重新初始化
    p = p + strlen("=");
    //去空格
    int trimflag = trimSpce(p, vbuf);
    if (trimflag != 0)
    {
        printf("trim error\n");
        return -3;
    }
    return 0;
}
int main(int arg, char *args[])
{
    int ret = 0;
    char vbuf[1024] = {0};
    int buflen = 0;
    char *kvbuf = "key1           =            fsfsfs";
    char *key = "key1";
    ret = getKeyByValue(kvbuf, key, vbuf);
    if (ret != 0)
    {
        printf("error");
        return ret;
    }
    printf("vbuf:%s\n", vbuf);
    printf("hello,world");
    system("pause");
    return 1;
}