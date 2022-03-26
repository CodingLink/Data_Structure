//
// Created by yoran on 2022/3/24.
//链表

#include<iostream>
typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode* next;
}LNode,*LinkList;


//头插法建立单链表
LinkList Link_HeadInsert(LinkList& L) {
    LNode* s=NULL;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf ("%d", &x);
    while (x != 9999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

//尾插法建立单链表
LinkList Link_TailInsert(LinkList& L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode* s, * r = L;
    scanf_s("%d", &x);
    while (x != 9999)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;;
        r->next = s;
        r = s;
        scanf_s("%d", &x);
    }
    r->next = NULL;
    return L;
}

//按序号查找元素
LNode* GetElem(LinkList L, int i)
{
    if (0==i) {
        return L;
    }
    if (i < 1)
    {
        return NULL;
    }
    LNode* p = L;

    for (int j = 0; j < i; j++)
    {
        p = p->next;
    }
    return p;
}

//按值查找结点
LNode* LocateElem(LinkList L, ElemType e)
{
    LNode* p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}

//插入结点
bool ListInsert(LinkList& L, int i, ElemType e)
{
    LNode* p = GetElem(L, i - 1);
    if (NULL==p)
    {
        return false;
    }
    LNode* s;
    s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//删除结点
bool ListDelete(LinkList& L, int i, ElemType& e)
{
    LNode* p = GetElem(L, i-1);
    if (NULL==p)
    {
        return false;
    }
    LinkList q=p->next;
    if(NULL==q)
    {
        return false;
    }
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

//求表长
int Length(LinkList L)
{
    int i = 1;
    LNode* p = (LNode*)malloc(sizeof(LNode));
    p = L->next;
    while (p->next != NULL)
    {
        p = p->next;
        i++;
    }
    return i;
}

//打印链表的值
void PrintList(LinkList L)
{
    L=L->next;
    while (L!=NULL)
    {
        printf("%3d",L->data);
        L=L->next;
    }
    printf("\n");
}

//int main()
//{
//    ElemType e;
//    LinkList L;
//    Link_TailInsert(L);
//    ListInsert(L,3,3);
//    printList(L);
//    ListDelete(L,1,e);
//    PrintList(L);
//    return 0;
//}


