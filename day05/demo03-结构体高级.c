#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//一旦结构体定义下来，结构体成员的内存布局就已经定义好了
//可以通过age去求出大的结构体的内存地址
typedef struct AdvTeacher
{
    char name[64]; //64
    int age;       //4
    int p;         //4
    char *name2;   //4
} AdvTeacher;
int main01(int arg, char *args[])
{
    AdvTeacher t1;
    AdvTeacher *p1 = NULL;
    p1 - 1; //编译通过，运行通过,在cpu中运行根本就没有操作内存
    p1 - 2;
    p1 - p1;
    {
        //相对于结构体偏移了64
        int offsize = (int)&(p1->age);
        printf("offsize:%d\n", offsize);
    }

    // strcpy(p1, "dddddddd");
    printf("hello,world");
    system("pause");
    return 1;
}

int main(int arg, char *args[])
{
    AdvTeacher t1;
    AdvTeacher *p1 = NULL;
    p1 - 1; //编译通过，运行通过,在cpu中运行根本就没有操作内存
    p1 - 2;
    p1 - p1;
    {
        //相对于结构体偏移了64
        // int offsize = (int)&(p1->age);
        int offsize = (int)&(((AdvTeacher *)0)->age);
        printf("offsize:%d\n", offsize);
    }

    // strcpy(p1, "dddddddd");
    printf("hello,world");
    system("pause");
    return 1;
}