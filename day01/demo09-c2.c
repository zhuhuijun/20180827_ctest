#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/**
 * 1、为什么会引入数据类型？
 * 数据类型的本质:是固定大小内存块的别名
 * b与&b数组数据类型
 * 1、如何定义一个数组类型
 * 2、数组指针
 * 3、数组类型和数组指针类型的关联
 * 数据类型可以起别名
 * 
 * 
 * 
 * 
 * 
 */
typedef struct Teacher2
{
    char name[64];
    int age;
} Teacher2;

typedef int U32;
int main(int arg, char *args[])
{
    int a;     //告诉c编译器分配4个字节的内存
    int b[10]; //告诉c编译器分配40个字节的内存
    //b 与 &b
    //b代表数组首元素的地址
    //&b代表的是整个数组的地址
    //b+1与 &b+1
    printf("b:%d,b+1:%d,&b:%d,&b+1:%d\n", b, b + 1, &b, (&b + 1));
    printf("b size:%d\n", sizeof(b));     //40
    printf("a size:%d\n", sizeof(a));     //40
    printf("U32 size:%d\n", sizeof(U32)); //40
    struct Teacher2 t1;
    t1.age = 331;
    Teacher2 t2;
    t2.age = 89;
    {
        char *p2 = NULL;
        p2 = (char *)malloc(sizeof(char) * 100);
    }
    system("pause");
    return 1;
}