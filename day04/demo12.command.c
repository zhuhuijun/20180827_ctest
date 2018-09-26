#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main(int arg, char *args[], char **env)
{
    int i = 0;
    printf("********************* Begin argv ******************\n");
    for (i = 0; i < arg; i++)
    {
        printf("%s\n", args[i]);
    }
    printf("********************* End argv ********************\n");
    for (i = 0; i < arg; i++)
    {
        printf("%s\n", args[i]);
    }
    printf("********************* End argv ********************\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("********************* Begin env ******************\n");
    for (i = 0; env[i] != NULL; i++)
    {
        printf("%s\n", env[i]);
    }
    printf("********************* End env ********************\n");
    printf("hello,world");
    system("pause");
    return 1;
}