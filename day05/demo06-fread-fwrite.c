#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct AdvTeacher
{
    char name[64];
    int age;
} AdvTeacher;
void api_fwrite()
{
    int i = 0;
    FILE *fp = NULL;
    char *fileName = "d:/3.data";
    AdvTeacher tArray[4];
    int myN = 0;

    for (i = 0; i < 4; i++)
    {
        sprintf(tArray[i].name, "%d%d%d", i + 1, i + 1, i + 1);
        tArray[i].age = i + 31;
    }

    fp = fopen(fileName, "wb");
    if (fp == NULL)
    {
        printf("建立文件失败\n");
        return;
    }
    for (i = 0; i < 4; i++)
    {
        //_Check_return_opt_ _CRTIMP size_t __cdecl
        //	fwrite(_In_count_x_(_Size*_Count) const void * _Str, _In_ size_t _Size, _In_ size_t _Count, _Inout_ FILE * _File);
        //函数参数
        //_Str : 从内存块的开始
        //_Size  //内存打包技术
        //_Count 写多少次
        //_File : 写入到 文件指针 所指向的文件中

        //函数的返回值
        myN = fwrite(&tArray[i], sizeof(AdvTeacher), 1, fp);

        //myN 判断 有没有写满  磁盘
    }

    if (fp != NULL)
    {
        fclose(fp);
    }
}

void api_fread()
{
    FILE *fp = NULL;
    int i = 0;
    char *filename = "d:/3.data";
    AdvTeacher tArray[4];
    int myn = 0;
    fp = fopen(filename, "r+b");

    if (fp == NULL)
    {
        printf("build file error\n");
    }
    for (i = 0; i < 4; i++)
    {
        fread(&tArray[i], sizeof(AdvTeacher), 1, fp);
        //myn判断有没有写满
    }
    if (fp != NULL)
    {
        fclose(fp);
    }
    for (i = 0; i < 4; i++)
    {
        printf("teacher%d:name:%s,age:%d\n", i, tArray[i].name, tArray[i].age);
    }
}
int main(int arg, char *args[])
{
    api_fwrite();
    api_fread();
    printf("hello,world");
    system("pause");
    return 1;
}