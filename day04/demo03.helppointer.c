#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int getMem(char ***psource, int count)
{
    char **p = NULL;
    int i = 0;
    p = (char **)malloc(sizeof(char *) * count); //char *arr[10];
    if (p == NULL)
    {
        return -1;
    }
    for (i = 0; i < count; i++)
    {
        p[i] = (char *)malloc(30 * sizeof(char));
        p[i][0] = '\0';
    }
    *psource = p;
    return 0;
}
char **splitstr(char *old, char split, int *count)
{
    char *p = NULL, *ptmp = NULL;
    int tmpcount = 0;
    if (old == NULL || count == NULL)
    {
        return NULL;
    }
    char **target = NULL;
    p = old;
    ptmp = old;
    //?????count
    do
    {
        p = strchr(p, split);
        if (p != NULL)
        {
            if (p - ptmp > 0)
            {
                tmpcount++;
                ptmp = p = p + 1;
            }
        }
        else
        {
            break;
        }
    } while (*p != '\0');
    int tt = getMem(&target, tmpcount);
    *count = tmpcount;
    tmpcount = 0;
    p = old;
    ptmp = old;
    do
    {
        p = strchr(p, split);
        if (p != NULL)
        {
            if (p - ptmp > 0)
            {
                strncpy(target[tmpcount], ptmp, p - ptmp);
                target[tmpcount][p - ptmp] = '\0'; //c风格结尾
                tmpcount++;
                ptmp = p = p + 1;
            }
        }
        else
        {
            break;
        }
    } while (*p != '\0');

    return target;
}

int getMem_Free(char ***psource, int count)
{
    int i = 0;
    char **tmp = NULL;
    if (psource == NULL)
    {
        return -1;
    }
    tmp = *psource;
    for (i = 0; i < count; i++)
    {
        if (tmp[i] != NULL)
        {
            free(tmp[i]);
        }
    }
    free(tmp);
    *psource = NULL;
}
int main(int arg, char *args[])
{
    char *p1 = "aaaa,bbbb,cccc,dddd,eeee";
    char ctm = ',';
    int count = 0;
    int i = 0;
    char **p = NULL;
    p = splitstr(p1, ctm, &count);
    printf("%d\n", count);
    for (i = 0; i < count; i++)
    {
        printf("%s\n", p[i]);
    }
    getMem_Free(&p, count);
    printf("hello,world");
    system("pause");
    return 1;
}
