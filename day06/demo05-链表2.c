#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct Teacher
{
    int data;
    Teacher *next;
} Teacher;

Teacher *CreateTeachers()
{
    //这些是栈上的会消失
    Teacher t1;
    Teacher t2;
    Teacher t3;
    Teacher t4;
    Teacher *p = NULL;

    t1.data = 1;
    t2.data = 2;
    t3.data = 3;
    t4.data = 4;

    t1.next = &t2;
    t2.next = &t3;
    t3.next = &t4;
    t4.next = NULL;
    p = &t1;
    while (p)
    {
        printf("data:%d\n", p->data);
        p = p->next;
    }
    return &t1;
}

int main(int arg, char *args[])
{
    //这种静态链表返回后节点都会消失，因为生命周期结束了
    Teacher *tmp = CreateTeachers();
    printf("hello,world");
    system("pause");
    return 1;
}