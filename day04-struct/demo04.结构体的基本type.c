#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//定义结构体类型
//定义了一个数据类型，固定大小内存块的别名，还没有分配内存
typedef struct Teacher
{
    char name[64];
    int age;
    int id;
} Teacher;
void printTeacher(Teacher *arr, int num)
{
    int i = 0;
    for (i = 0; i < num; i++)
    {
        printf("the age of teacher%d:%d\n", i, arr[i].age);
    }
}
void sortTeacher(Teacher *arr, int num)
{
    int i = 0;
    int j = 0;
    Teacher tmp;
    for (i = 0; i < num; i++)
    {
        for (j = i; j < num; j++)
        {
            if (arr[i].age > arr[j].age)
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
Teacher *createArr(int num)
{
    Teacher *tmp = NULL;
    tmp = (Teacher *)malloc(sizeof(Teacher) * num);
    if (tmp == NULL)
    {
        return NULL;
    }
    return tmp;
}
void FreeTeacher(Teacher *t)
{
    if (t != NULL)
    {
        free(t);
    }
}
//匿名定义变量
int main(int arg, char *args[])
{
    int i = 0;
    //Teacher TeacherArr[3];
    int num = 3;
    Teacher *TeacherArr = NULL;
    TeacherArr = createArr(num);
    for (i = 0; i < num; i++)
    {
        printf("\nplease enter age of teacher%d:", i);
        scanf("%d", &(TeacherArr[i].age));
    }
    printTeacher(TeacherArr, 3);
    sortTeacher(TeacherArr, 3);
    printf("sort after.....\n");
    printTeacher(TeacherArr, 3);
    FreeTeacher(TeacherArr);
    printf("hello,world");
    system("pause");
    return 1;
}