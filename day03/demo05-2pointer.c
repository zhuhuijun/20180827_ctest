#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/***---------------------------------------------------------
 *1、二级指针做输入指的是在主调函数分配内存
 *2、二级指针做输出指的是在被调用函数中分配内存
 */
int getmem(char **mp1, int *len1, char **mp2, int *len2)
{
    char *tmp1 = NULL;
    char *tmp2 = NULL;
    tmp1 = (char *)malloc(100);
    if (tmp1 == NULL)
    {
        return -1;
    }
    strcpy(tmp1, "abcdef");
    *len1 = strlen(tmp1);
    *mp1 = tmp1;

    tmp2 = (char *)malloc(100);
    if (tmp2 == NULL)
    {
        return -1;
    }
    strcpy(tmp2, "123456");
    *len2 = strlen(tmp2);
    *mp2 = tmp2;

    return 1;
}
void getmem_free(char **mm)
{
    char *tmp = NULL;
    if (mm == NULL)
    {
        return;
    }
    tmp = *mm;
    free(tmp);  //释放指针变量指向的内存空间
    *mm = NULL; //把指针变量实参置为iNULL
}
int main(int arg, char *args[])
{
    char *p1 = NULL;
    printf("p1:%p\n", p1);
    int len1 = 0;
    char *p2 = NULL;
    int len2 = 0;
    getmem(&p1, &len1, &p2, &len2);
    printf("p1:%p\n", p1);
    printf("p1:%s\n", p1);
    printf("p2:%s\n", p2);
    getmem_free(&p1);
    getmem_free(&p2);
    printf("hello,world");
    system("pause");
    return 1;
}