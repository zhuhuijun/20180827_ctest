#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int searchKeyTable(char *table[], int size, char *key, int *pos)
{
    int rv = 0;
    int i = 0;
    int inum = 0;
    if (table == NULL || key == NULL || pos == NULL)
    {
        rv = -1;
        printf("func null pointer\n");
        return rv;
    }
    //此处已经退化为指针了，在这里执行时的长度为1
    //inum = sizeof(table) / (sizeof(*table));
    for (i = 0; i < size; i++)
    {
        if (strcmp(key, table[i]) == 0)
        {
            *pos = i;
            return rv;
        }
    }

    if (i == size)
    {
        *pos = -1;
    }
    return rv;
}
#define DIM(a) (sizeof(a) / sizeof(*a))
int main(int arg, char *args[])
{
    int inum = 0;
    int pos = 0;
    int a[10];
    int i = 0;
    //指针数组
    char *c_keyword[] = {
        "while",
        "case",
        "static",
        "do"};
    searchKeyTable(c_keyword, DIM(c_keyword), "do", &pos);
    printf("pos:%d\n", pos);
    searchKeyTable(c_keyword, DIM(c_keyword), "static", &pos);
    printf("pos:%d\n", pos);
    printf("hello,world");
    system("pause");
    return 1;
}