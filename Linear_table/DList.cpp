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
        //TODO
        if(L->next->next!=NULL)
        {
            L->next->prior=s;
        }
        s->prior = L;
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
    //TODO
    r->next=NULL;
    return L;
}

//根据序号查找结点
DNode *GetElem(DLinkList L,int i)
{
    int j=1;
    DNode* p=L->next;
    if(0==i)
    {
        return L;
    }
    if(i<0)
    {
        return NULL;
    }
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }
    return p;
}
//双链表插入结点
bool DList_Insert(DLinkList& L, int i,ElemType e)
{
    DNode* p = GetElem(L,i-1);
    if(NULL==p)
    {
        return false;
    }
    DNode* s = (DNode*)malloc(sizeof(DNode));
    s->data = e;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}
//删除结点
bool DList_delete(DLinkList& L, int i, ElemType& e)
{
    DNode* p = GetElem(L,i-1);
    if(NULL==p)
    {
        return false;
    }
    DLinkList q=p->next;
    if(NULL==q)
    {
        return false;
    }
    p->next=q->next;
    if(q->next!=NULL)
    {
        q->next->prior=p;
    }
    free(q);
    return true;
}

//链表打印
void PrintDList(DLinkList L)
{
    L=L->next;
    while(L!=NULL)
    {
        printf("%3d",L->data);
        L=L->next;
    }
    printf("\n");
}
//
//int main()
//{
//    ElemType e;
//    DLinkList L;
//    DList_TailInsert(L);
//    PrintDList(L);
//    DList_Insert(L, 3, 10);
//    PrintDList(L);
//    DList_delete(L, 5, e);
//    PrintDList(L);
//    return 0;
//}
