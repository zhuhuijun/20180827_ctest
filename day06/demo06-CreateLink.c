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
int SList_Reverse(SLIST *phead);              /*逆序*/
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
//插入节点
int Slist_Insert(SLIST *phead, int x, int y)
{
    SLIST *pHead, *pCur, *pM, *pPre;
    int data;
    //创建新的业务节点
    pM = (SLIST *)malloc(sizeof(SLIST));
    if (pM == NULL)
    {
        return -1;
    }
    pM->next = NULL;
    pM->data = y;
    pPre = phead;
    pCur = phead->next;
    while (pCur)
    {
        if (pCur->data == x)
        {
            break;
        }
        pPre = pCur;
        pCur = pCur->next;
    }
    //让新节点连接后续节点
    pM->next = pPre->next;
    pPre->next = pM;
}
//删除节点
int SList_DelNode(SLIST *phead, int y)
{
    SLIST *pHead, *pCur, *pPre;
    int data;
    int ret = 0;
    if (phead == NULL)
    {
        return -1;
    }
    pPre = phead;
    pCur = phead->next;
    while (pCur)
    {
        if (pCur->data == y)
        {
            break;
        }
        pPre = pCur;
        pCur = pCur->next;
    }
    if (pCur == NULL)
    {
        printf("no find node->data=%d\n", y);
        return -2;
    }
    pPre->next = pCur->next;
    if (pCur != NULL)
    {
        free(pCur);
    }
    return 0;
}
//销毁
int SList_Destory(SLIST *phead)
{
    SLIST *tmp = NULL;
    if (phead == NULL)
    {
        return -1;
    }
    tmp = phead;
    while (phead != NULL)
    {
        tmp = phead->next;
        free(phead);
        phead = tmp;
    }
}
//逆序链表
int SList_Reverse(SLIST *phead)
{
    SLIST *p = NULL; //前驱指针
    SLIST *q = NULL; //当前指针
    SLIST *t = NULL; //缓存的一个节点
    if (phead == NULL || phead->next == NULL || (phead->next->next == NULL))
    {
        return 0;
    }
    p = phead->next;
    q = phead->next->next;
    while (q)
    {
        t = q->next; //缓存后面的链表
        q->next = p; //逆序
        p = q;       //让p下移动一个节点
        q = t;       //
    }
    phead->next->next = NULL; //头节点变为null
    phead->next = p;          //最后的p变为头节点
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
    Slist_Insert(phead, 20, 19);
    printf("insert after....\n");
    SList_Print(phead);
    SList_DelNode(phead, 19);
    printf("delete after....\n");
    SList_Print(phead);
    SList_Reverse(phead);
    printf("reverse after....\n");
    SList_Print(phead);
    printf("hello,world");
    system("pause");
    return 1;
}