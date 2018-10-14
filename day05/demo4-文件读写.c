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
int api_fputc()
{
    FILE *fp = NULL;
    int i = 0;
    char *filename = "d:/1.txt";
    fp = fopen(filename, "r+");
    char a[27] = "abcdefghijk";
    if (fp == NULL)
    {
        printf("open file is error\n");

        return -1;
    }
    printf("open file success\n");
    for (i = 0; i < strlen(a); i++)
    {
        fputc(a[i], fp);
    }
    //文件中写数据
    if (fp != NULL)
    {
        fclose(fp);
    }
    //句柄:内存快的首地址
    return 1;
}

int api_fgetc()
{
    FILE *fp = NULL;
    char *filename = "d:/1.txt";
    fp = fopen(filename, "r+");
    char a[27] = "abcdefghijk";
    if (fp == NULL)
    {
        printf("open file is error\n");

        return -1;
    }
    printf("open file success\n");
    while (!feof(fp))
    {
        char tmpc = fgetc(fp);
        printf("%c", tmpc);
    }

    if (fp != NULL)
    {
        fclose(fp);
    }
    //句柄:内存快的首地址
    return 1;
}

int main(int arg, char *args[])
{
    //api_fputc();
    api_fgetc();
    printf("hello,world");
    system("pause");
    return 1;
}