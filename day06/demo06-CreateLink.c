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
    SLIST *pHead, *pCur, *pM;
    int data;
    //create head node and init
    pHead = (SLIST *)malloc(sizeof(SLIST));
    if (pHead == NULL)
    {
        return NULL;
    }
    pCur = pHead;
    printf("\nplease enter data:");
    scanf("%d", &data);
    while (data != -1)
    {
        //1、创建新链表
        pM = (SLIST *)malloc(sizeof(SLIST));
        if (pM == NULL)
        {
            return NULL;
        }
        pM->data = data;
        pM->next = NULL;
        //2、新节点如链表
        pCur->next = pM;
        //3、新节点变成当前节点
        pCur = pM;
        printf("\nplease enter data:");
        scanf("%d", &data);
    }
    return pHead;
}
//打印链表
int SList_Print(SLIST *phead)
{
    int ret = 0;
    if (phead == NULL)
    {
        return -1;
    }
    SLIST *tmp = NULL;
    tmp = phead->next;
    while (tmp)
    {
        printf("\ndata:%d\n", tmp->data);
        tmp = tmp->next;
    }
    return ret;
}
/******************************************************************/
int main(int arg, char *args[])
{
    SLIST *phead = NULL;
    phead = Slist_Create();
    if (phead == NULL)
    {
        printf("error create link\n");
        return 0;
    }
    SList_Print(phead);
    printf("hello,world");
    system("pause");
    return 1;
}