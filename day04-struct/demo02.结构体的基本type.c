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
//结构体元素做函数参数
void copyTacher(Teacher to, Teacher from)
{
    to = from; //从from到to和t1,t3没关系
}
void copyTacher2(Teacher *to, Teacher *from)
{
    (*to) = (*from); //从from到to和t1,t3没关系
}
//匿名定义变量
int main(int arg, char *args[])
{
    struct Teacher t1 = {"aaaa", 34, 2}; //告诉编译器分配内存
    Teacher t2;
    Teacher t3;
    t2 = t1; //编译器的xi
    printf("t2.name=%s\n", t2.name);
    printf("t2.age=%d\n", t2.age);
    //copyTacher(t1, t3);
    copyTacher2(&t3, &t1);
    printf("t3.name=%s\n", t3.name);
    printf("t3.age=%d\n", t3.age);
    printf("hello,world");
    system("pause");
    return 1;
}