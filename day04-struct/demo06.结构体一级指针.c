#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//定义结构体类型
//定义了一个数据类型，固定大小内存块的别名，还没有分配内存
typedef struct Teacher
{
    char name[64];
    char *alice;
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
int createArr(Teacher **arr, int num)
{

    Teacher *tmp = NULL;
    int i = 0;
    if (arr == NULL)
    {
        return -1;
    }
    tmp = (Teacher *)malloc(sizeof(Teacher) * num);
    if (tmp == NULL)
    {
        return -1;
    }
    memset(tmp, 0, sizeof(tmp));
    for (i = 0; i < num; i++)
    {
        tmp[i].alice = (char *)malloc(128);
    }
    *arr = tmp;
    return 0;
}
void FreeTeacher(Teacher **t, int num)
{
    Teacher *tm = *t;
    for (int i = 0; i < num; i++)
    {
        if (tm[i].alice != NULL)
        {
            free(tm[i].alice);
        }
    }
    if (tm != NULL)
    {
        free(tm);
    }
    *t = NULL;
}
//匿名定义变量
int main(int arg, char *args[])
{
    int i = 0;
    int num = 3;
    int ret = 0;
    Teacher *TeacherArr = NULL;
    ret = createArr(&TeacherArr, num);
    if (ret != 0)
    {
        printf("some error \n");
        return 0;
    }
    for (i = 0; i < num; i++)
    {
        printf("\nplease enter age of teacher%d:", i);
        scanf("%d", &(TeacherArr[i].age));
        printf("\nplease enter name of teacher%d:", i);
        scanf("%s", TeacherArr[i].name); //向指针所指向的内存空间中copy数据
        printf("\nplease enter alice of teacher%d:", i);
        scanf("%s", TeacherArr[i].alice); //向指针所指向的内存空间中copy数据
    }
    printTeacher(TeacherArr, num);
    sortTeacher(TeacherArr, num);
    printf("sort after.....\n");
    printTeacher(TeacherArr, num);
    FreeTeacher(&TeacherArr, num);
    printf("hello,world");
    system("pause");
    return 1;
}