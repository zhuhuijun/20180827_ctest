#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int splitstr(char *buf1, char c, char buf2[10][30], int *count)
{
    //strcpy(buf2[0], "aaaa");
    //strcpy(buf2[1], "aaaa");
    char *p = NULL;
    char *tmpP = NULL;
    int tmpcount = 0;
    p = buf1;
    tmpP = buf1;
    do
    {
        //2.检索符合条件的位置p后移，形成插值，挖字符串
        p = strchr(p, c);
        if (p != NULL)
        {
            if (p - tmpP > 0)
            {
                strncpy(buf2[tmpcount], tmpP, p - tmpP);
                buf2[tmpcount][p - tmpP] = '\0'; //把第一行数据变成c风格的字符传
                tmpcount++;
                tmpP = p = p + 1;
            }
        }
        else
        {
            break;
        }
    } while (*p != '\0');
    *count = tmpcount;
    return 0;
}

int main(int arg, char *args[])
{
    char *p1 = "aaaa,bbbb,cccc,dddd,eeee";
    char ctm = ',';
    char marr[10][30] = {0};
    int count = 0;
    int i = 0;
    int ret = splitstr(p1, ctm, marr, &count);
    if (ret != 0)
    {
        printf("error\n");
        return 0;
    }
    for (i = 0; i < count; i++)
    {
        printf("one:%s\n", marr[i]);
    }
    printf("hello,world");
    system("pause");
    return 1;
}