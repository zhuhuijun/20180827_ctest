#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct Node
{
    int data;
    struct Node *next;
} SLIST;
SLIST *Slist_Create();
int SList_Print(SLIST *phead);                /*遍历链表*/
int Slist_Insert(SLIST *phead, int x, int y); /*插入节点*/
int SList_DelNode(SLIST *phead, int y);       /*删除节点*/
int SList_Destory(SLIST *phead);              /*销毁链表*/
/******************************************************************/
//创建链表
SLIST *Slist_Create()
{
    return NULL;
}
//打印链表
int SList_Print(SLIST *phead)
{
    int ret = 0;
    return ret;
}
/******************************************************************/
int main(int arg, char *args[])
{
    SLIST *phead = NULL;
    phead = Slist_Create();
    SList_Print(phead);
    printf("hello,world");
    system("pause");
    return 1;
}