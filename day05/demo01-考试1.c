#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*************************************************
 *二级指针做函数参数的考试案例 
 * 
 * 
 * 
 * 
 * 
 */
int sort(char **myp1, int num1, char (*myp2)[30], int num2, char ***myp3, int *num3)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int tmplen = 0;
    char **p3 = NULL;
    char *tmp = NULL;
    p3 = (char **)malloc((num1 + num2) * sizeof(char *));
    if (p3 == NULL)
    {
        return -1;
    }
    for (i = 0; i < num1; i++)
    {
        tmplen = strlen(myp1[i]) + 1;
        p3[i] = (char *)malloc(sizeof(char) * tmplen);
        if (p3[i] == NULL)
        {
            return -2;
        }
        strcpy(p3[i], myp1[i]);
    }
    for (j = 0; j < num2; j++)
    {
        tmplen = strlen(myp2[j]) + 1;
        p3[i] = (char *)malloc(sizeof(char) * tmplen);
        if (p3[i] == NULL)
        {
            return -2;
        }
        strcpy(p3[i], myp2[j]);
        i++;
    }

    *num3 = num1 + num2;
    tmplen = *num3;
    //排序可以交换地址也可以交换内容
    for (i = 0; i < tmplen; i++)
    {
        for (j = i + 1; j < tmplen; j++)
        {
            if (strcmp(p3[i], p3[j]) > 0)
            {
                tmp = p3[i];
                p3[i] = p3[j];
                p3[j] = tmp;
            }
        }
    }
    *myp3 = p3;
    return 0;
}

void freeSort(char **p, int num)
{
    int i = 0;
    if (p == NULL)
    {
        return;
    }
    for (i = 0; i < num; i++)
    {
        free(p[i]);
    }
    free(p);
}

void freeSort01(char ***p, int num)
{
    int i = 0;
    char **tmp = NULL;
    if (p == NULL)
    {
        return;
    }
    tmp = *p;
    for (i = 0; i < num; i++)
    {
        free(tmp[i]);
    }
    free(tmp);
    *p = NULL;
}
int main(int arg, char *args[])
{
    char *p1[] = {"aaa", "ccc", "000"};
    char buf2[10][30] = {"333", "bbb"};
    char **p3 = NULL;
    int len1, len2, len3, i;
    len1 = sizeof(p1) / (sizeof(*p1));
    len2 = 3;
    int ret = sort(p1, len1, buf2, len2, &p3, &len3);
    if (ret != 0)
    {
        printf("some error：%d\n", ret);
        return 0;
    }
    for (i = 0; i < len3; i++)
    {
        printf("%s\n", p3[i]);
    }
    freeSort01(&p3, len3);
    printf("hello,world");
    system("pause");
    return 1;
}