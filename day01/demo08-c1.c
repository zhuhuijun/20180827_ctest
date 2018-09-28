#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/**
 * 数组做函数参数的退化问题
 * 会退化成指针
 * 把数组的首地址和长度传给函数
 */
//void printArray(int a[8], int num)
//void printArray(int a[], int num)
void printArray(int *a, int num)
{
    int i = 0;
    int num2 = 0;
    /*数组退化成指针,a就是4个字节的指针*/
    num2 = sizeof(a) / sizeof(a[0]);
    printf("num2=%d\n", num2);
    for (i = 0; i < num; i++)
    {
        printf("%d\r\n", a[i]);
    }
}
/**
 * 排序 
 */
void sortArray(int *a, int num)
{
    int i, j, tmp;
    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (a[i] > a[j])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
int main(int arg, char *args[])
{
    int i = 0, j = 0;
    int tmp = 0;
    int num = 0;
    num = 8;
    int a[] = {34, 45, 323, 45, 545, 2323, 55, 45};
    num = sizeof(a) / sizeof(a[0]);
    printArray(a, num);
    sortArray(a, num);
    printf("排序后\n");
    printArray(a, num);
    system("pause");
    return 1;
}