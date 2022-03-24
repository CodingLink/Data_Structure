//
// Created by yoran on 2022/3/24.
//

#include<cstdio>
#include<malloc.h>
typedef int ElemType;

typedef struct DNode {
    ElemType data;
    struct DNode* prior, * next;
}DNode,*DLinkList;

//头插法创建双链表
DLinkList DList_HeadInsert(DLinkList& L)
{
    DNode* s = NULL;
    int x;
    L = (DLinkList)malloc(sizeof(DLinkList));
    L->next = NULL;
    L->prior = NULL;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (DNode*)malloc(sizeof(DNode));
        s->data = x;
        s->next = L->next;
        s->prior = L->prior;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

//尾插法建立双链表
DLinkList DList_TailInsert(DLinkList& L)
{
    int x;
    L = (DLinkList)malloc(sizeof(DLinkList));
    DNode* s, * r = L;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (DNode*)malloc(sizeof(DNode));
        s->data = x;
        s->next = r->next;
        s->prior = r;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    return L;
}

//双链表插入结点
bool DList_Insert(DLinkList& L, int i,ElemType e)
{
    if (i < 1)
    {
        return false;
    }
    DNode* s = (DNode*)malloc(sizeof(DNode));
    s->data = e;
    int j = 0;
    DNode* p = L;
    while (j < i-1&&p->next)
    {
        p = p->next;
        j++;
    }
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}
//删除结点
bool DList_delete(DLinkList& L, int i, ElemType& e)
{
    if (0 == i)
    {
        return L;
    }
    if (i < 1)
    {
        return NULL;
    }
    int j = 0;
    DNode* p = L;
    while (j < i - 1 && p)
    {
        p = p->next;
        j++;
    }
    if (p->next->next==NULL)
    {
        e = p->next->data;
        DNode* q = p->next;
        p->next = NULL;
        free(q);
        return true;
    }
    e = p->next->data;
    DNode* q = p->next;
    q->next->prior = p;
    p->next = q->next;
    free(q);
    return true;
}

//int main()
//{
//    ElemType e;
//    DLinkList L;
//    DList_TailInsert(L);
//    DList_Insert(L, 3, 100);
//    DList_delete(L, 2, e);
//}