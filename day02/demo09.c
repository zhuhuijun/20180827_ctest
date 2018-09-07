#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/**
 * 1、字符串做函数参数
 * 
 */
int main01(int arg, char *args[])
{

    //全局去声明字符串copy到栈区
    char a[] = "i am a student";
    char buf[64];
    int i = 0;
    for (i = 0; *(a + i) != '\0'; i++)
    {
        //完成内存数据的copy,a的地址值不变,\0没有copy
        *(buf + i) = *(a + i);
    }
    //一定要显示的将\0加上
    buf[i] = '\0';
    printf("buf:%s\n", buf);
    printf("a:%s\n", a);
    printf("hello,world");
    system("pause");
    return 1;
}
//不断的修改from和to的指向
void copyStr1(char *from, char *to)
{
    for (; *from != '\0'; from++, to++)
    {
        *to = *from;
    }
    *to = '\0';
}
void copyStr2(char *from, char *to)
{
    for (; *from != '\0';)
    {
        *to++ = *from++;
    }
    *to = '\0';
}
void copyStr3(char *from, char *to)
{
    while ((*to = *from) != '\0')
    {
        from++;
        to++;
    }
}
void copyStr4(char *from, char *to)
{
    while ((*to++ = *from++) != '\0')
    {
        ;
    }
}
void copyStr5(char *from, char *to)
{
    int ret = 0;
    if (from == NULL || to == NULL)
    {
        ret = -1;
        return ret;
    }
    printf("from:%s \n", from);
    char *tmpfrom = NULL;
    char *tmpto = NULL;
    tmpfrom = from;
    tmpto = to;
    //form形参 形参to 的值 不停的在变化....
    //不断的修改了myfrom和myto的指向
    while (*tmpto++ = *tmpfrom++) //*操作 和++的操作; ++ 优先级高 //  后置++，先 *to = *from;  再from++, to++
    {
        ;
    }
    //没有缓冲就无法打印
    printf("from:%s \n", from);
    return ret;
}
//字符串函数参数copy推演
int main(int arg, char *args[])
{
    char *from = "aaaaaaa";
    char to[100];
    copyStr1(from, to);
    printf("to:%s\n", to);
    copyStr2(from, to);
    printf("to:%s\n", to);
    copyStr3(from, to);
    printf("to:%s\n", to);
    copyStr4(from, to);
    printf("to:%s\n", to);
    printf("hello,world");
    system("pause");
    return 1;
}