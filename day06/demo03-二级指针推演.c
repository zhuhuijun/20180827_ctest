#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
void change(char **pp2)
{
    //char *p3 = "ddd";
    //*pp2 = p3; //间接修改
    char *tmp = NULL;
    tmp = (char *)malloc(100);
    strcpy(tmp, "aaaafafafaff");
    *pp2 = tmp;
}
int main(int arg, char *args[])
{
    char *p = NULL;
    char *p1 = "aaaa";
    char *p3 = "333";
    char **pp2 = NULL;
    p = p1; //直接修改p的值
    printf("p = %s\n", p);
    printf("p address:%p\n", p);

    {
        pp2 = &p;
        *pp2 = p3; //间接修改
        printf("p = %s\n", p);
        printf("p address:%p\n", p);
    }
    change(&p);
    printf("p = %s\n", p);
    printf("p address:%p\n", p);
    printf("hello,world");
    system("pause");
    return 1;
}