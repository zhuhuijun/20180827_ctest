#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//定义结构体类型
//定义了一个数据类型，固定大小内存块的别名，还没有分配内存
typedef struct Teacher
{
    char name[64];
    int age;
    int id;
} Teacher;
struct Student
{
    char name[64];
    int age;
    int id;
} s1, s2;
struct
{
    char name[64];
    int age;
    int id;
} s3 = {"af", 1, 2}, s4 = {"fafa", 23, 1};
//匿名定义变量
int main(int arg, char *args[])
{
    struct Teacher t1; //告诉编译器分配内存
    strcpy(t1.name, "fssssssss");
    t1.age = 34;
    t1.id = 5;
    Teacher t2 = {"aaaaaa", 34, 4};
    Teacher *t3 = NULL;
    t3 = &t2;
    printf("age=%d\n", t3->age);
    //寻址操作在cpu里面
    printf("name=%s\n", t3->name);
    printf("hello,world");
    system("pause");
    return 1;
}