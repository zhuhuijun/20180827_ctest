#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
char *getTemp()
{
    char *p = NULL;
    p = "adddd";
    return p;
}
int main(int arg, char *args[])
{
    char *p = getTemp();
    printf("p:%s\n", p);
    //*(p + 2) = "2";
    printf("hello,world");
    system("pause");
    return 1;
}