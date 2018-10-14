#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*************************************************************
 * 文本文件
 * 二进制文件
 * 文件的读写方式
 * 1、按照字符的方式 fgetc fputc
 * 2、按照行读写的方式 fgets fputs
 * 3、按照块的方式     fread fwrite
 * 
 * 
 * 
 */

char *mygets(char *p, int max, FILE *fp)
{
    strcpy(p, "aaaaaaaaa");
    return p;
}
int api_fputs()
{
    FILE *fp = NULL;
    int i = 0;
    char *filename = "d:/11.txt";
    fp = fopen(filename, "w+");
    char a[27] = "111111111111111abcdefghijk";
    if (fp == NULL)
    {
        printf("open file is error\n");

        return -1;
    }
    printf("open file success\n");
    fputs(a, fp);
    //文件中写数据
    if (fp != NULL)
    {
        fclose(fp);
    }
    //句柄:内存快的首地址
    return 1;
}

int api_fgets()
{
    FILE *fp = NULL;
    char buf[1024];
    char *filename = "d:/11.txt";
    fp = fopen(filename, "r+");
    char a[27] = "111111111afafafabcdefghijk";
    if (fp == NULL)
    {
        printf("open file is error\n");

        return -1;
    }
    printf("open file success\n");
    while (!feof(fp))
    {
        //C 函数库 会将一行一行的数据copy到buf所指向的内存空间中，并且变成C风格的字符串
        //以\0结尾
        char *pp = fgets(buf, 1024, fp);
        if (pp == NULL)
        {
            goto End;
        }
        printf("%s\n", buf);
    }
End:
    if (fp != NULL)
    {
        fclose(fp);
    }
    //句柄:内存快的首地址
    return 1;
}

int main(int arg, char *args[])
{
    api_fputs();
    api_fgets();
    printf("hello,world");
    system("pause");
    return 1;
}