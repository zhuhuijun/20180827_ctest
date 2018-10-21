#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct Student
{
    char name[64];
    int id;
} Student;

typedef struct Teacher
{
    char name[64];
    int id;
    char *p1;
    char **p2;
    Student stu;
    Student *st1;
    Teacher *pt;
} Teacher;

int main(int arg, char *args[])
{
    Teacher t1;
    printf("hello,world");
    system("pause");
    return 1;
}