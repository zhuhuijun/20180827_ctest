#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
char g_buf[1024];
int reverse(char *bbuf)
{
    int ret = 0;
    if (bbuf == NULL)
    {
        return -1;
    }
    int length = strlen(bbuf);
    char *p1 = bbuf;
    char *p2 = bbuf + length - 1;
    while (p1 < p2)
    {
        char c = *p1;
        *p1 = *p2;
        *p2 = c;
        ++p1;
        --p2;
    }
    return ret;
}
//逆序的结果需要保存到全局中
void inverde02(char *p)
{
    //递归结束的异常条件
    if (p == NULL)
    {
        return;
    }
    //递归结束条件
    if (*p == '\0')
    {
        return;
    }
    inverde02(p + 1); //注意此时没有只从打印
    //，而是执行了让字符串的每个地址入栈
    printf("%c\n", *p);
}
//递归和非全局变量（递归指针做函数参数）
void inverde03(char *p)
{
    //递归结束的异常条件
    if (p == NULL)
    {
        return;
    }
    //递归结束条件
    if (*p == '\0')
    {
        return;
    }
    inverde03(p + 1); //注意此时没有只从打印
                      //，而是执行了让字符串的每个地址入栈
    //strcpy(g_buf, p);
    //strncpy(g_buf, p, 1);
    strncat(g_buf, p, 1);
}
void inverde04(char *p, char *mbuf)
{
    //递归结束的异常条件
    if (p == NULL || mbuf == NULL)
    {
        return;
    }
    //递归结束条件
    if (*p == '\0')
    {
        return;
    }
    inverde04(p + 1, mbuf); //注意此时没有只从打印
                            //，而是执行了让字符串的每个地址入栈
    //strcpy(g_buf, p);
    //strncpy(g_buf, p, 1);
    strncat(mbuf, p, 1);
}
int main(int arg, char *args[])
{
    memset(g_buf, 0, sizeof(g_buf));
    char bbuf[] = "abcdefg";
    printf("old:%s\n", bbuf);

    char mbuf[1024] = {0};
    inverde04(bbuf, mbuf);
    printf("mbuf:%s\n", mbuf);

    int length = strlen(bbuf);
    char *p1 = bbuf;
    char *p2 = bbuf + length - 1;
    while (p1 < p2)
    {
        char c = *p1;
        *p1 = *p2;
        *p2 = c;
        ++p1;
        --p2;
    }
    printf("new:%s\n", bbuf);
    reverse(bbuf); //抽取函数
    printf("new:%s\n", bbuf);
    inverde02(bbuf);
    inverde03(bbuf);
    printf("gbuf:%s\n", g_buf);

    printf("hello,world");
    system("pause");
    return 1;
}