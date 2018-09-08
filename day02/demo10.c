#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//char *p="abc4242424abcfsfsfs23232abcfsfs";//p中abc出现的次数
int main01(int arg, char *args[])
{
    char *p = "abc4242424abcfsfsfs23232abcfsfs";
    int ncount = 0;
    do
    {
        p = strstr(p, "abcd");
        if (p != NULL)
        {
            ncount++;
            p = p + strlen("abcd");
        }
        else
        {
            break;
        }
    } while (*p != '\0');
    printf("ncount:%d\n", ncount);
    printf("hello,world");
    system("pause");
    return 1;
}

int main02(int arg, char *args[])
{
    char *p = "abc4242424abcfsfsfs23232abcfsfs";
    int ncount = 0;
    while (p = strstr(p, "abc"))
    {
        ncount++;
        p = p + strlen("abc");
        if (*p == '\0')
        {
            break;
        }
    }
    printf("ncount:%d\n", ncount);
    printf("hello,world");
    system("pause");
    return 1;
}

int getStrCount(char *p, char *target, int *ncount)
{
    int nc = 0;
    int errcode = 0;
    if (p == NULL || target == NULL || ncount == NULL)
    {
        errcode = -1;
        return errcode;
    }
    char *tmp = NULL;
    tmp = p;
    do
    {
        tmp = strstr(tmp, target);
        if (tmp != NULL)
        {
            nc++;
            tmp = tmp + strlen(target);
        }
        else
        {
            break;
        }
    } while (*tmp != '\0');
    *ncount = nc;
    return errcode;
}
int main(int arg, char *args[])
{
    char *p = "abc4242424abcfsfsfs23232abcfsfs";
    int ncount = 0;
    char sub[] = "abc";
    int r = getStrCount(p, sub, &ncount);
    printf("mm=======ncount:%d\n", ncount);
    printf("hello,world");
    system("pause");
    return 1;
}