#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/**
 * 指针指向谁就把谁的地址付给指针
 * 指针变量和他所指向的内存空间的变量是两个不同的概念
 * 理解指针关键是理解内存，
 * 没有内存哪来的指针
 * 
 * 
 * 
 */
char *getStr1()
{
    char *p1 = "abc2";
    return p1;
}

char *getStr2()
{
    char *p1 = "abc2";
    return p1;
}
//堆上的分配
char *GetMem(int num)
{
    char *p1 = NULL;
    p1 = (char *)malloc(sizeof(char) * num);
    if (p1 == NULL)
    {
        return NULL;
    }
    return p1;
}
//不是把64个字节的内存块返回，而是内存块的首地址
char *GetMem2()
{
    char buf[64];
    strcpy("12334555", buf);
    printf("buf:%s\n", buf);
    //返回首地址，但是空间已经释放了
    return buf;
}
int main(int arg, char *args[])
{
    char *p1 = NULL;
    char *p2 = NULL;
    char *tmp = NULL;
    char *tmp2 = NULL;
    p1 = getStr1();
    p2 = getStr2();
    printf("p1:%s,p2:%s\n", p1, p2);
    printf("p2:%d,p2:%d\n", p1, p2);
    tmp = GetMem(10);
    if (tmp == NULL)
    {
        return 0;
    }
    strcpy(tmp, "456"); //向tmp指向的内存空间中copy数据
    printf("tmp:%s\n", tmp);

    //tmp2 = GetMem2();
    //printf("tmp2:%s\n", tmp2);
    printf("hello,world\n");
    system("pause");
    return 1;
}