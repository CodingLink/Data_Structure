//
// Created by yoran on 2022/3/24.
// 双链表
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;

typedef struct DLNode{
    ElemType data;
    struct DLNode *prior,*next;
}DLNode,*DLinkList;

//头插法创建双链表
void DLink_HeadInsert(DLinkList &DL)
{
    DL=(DLinkList) malloc(sizeof(DLinkList));
    DL->next=NULL;
    DL->prior=NULL;
    DL->data=NULL;
    DLNode* s;
    int x;
    scanf("%d",&x);
    while(x!=9999)
    {
        s=(DLNode*) malloc(sizeof (DLNode));
        s->data=x;
        s->next=DL->next;
        if(DL->next!=NULL)
        {
            DL->next->prior=s;
        }
        s->prior=DL;
        DL->next=s;
        scanf("%d",&x);
    }
}

//尾插法创建双链表
void DLink_TailInsert(DLinkList &DL)
{
    DL=(DLinkList) malloc(sizeof (DLinkList));
    DL->prior=NULL;
    DL->next=NULL;
    DL->data=NULL;
    DLNode *s,*r=DL;
    int x;
    scanf("%d",&x);
    while(x!=9999)
    {
        s=(DLNode*) malloc(sizeof (DLNode));
        s->data=x;
//        s->next=r->next;
        s->prior=r;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;
}

// 按序号查找元素
DLNode *GetElem(DLinkList DL,int i)
{
    if(i==0)
        return DL;
    if(i<1)
        return NULL;
    DLNode *p=DL->next;
    int j=1;
    while(p!=NULL&&j<i)
    {
        p=p->next;
        j++;
    }
    return p;
}

//插入元素
bool DList_Insert(DLinkList &DL,int i,ElemType e)
{
    DLNode *p= GetElem(DL,i-1);
    if(NULL==p)
    {
        return false;
    }
    DLNode *s=(DLNode*) malloc(sizeof(DLNode));
    s->data=e;
    s->next=p->next;
    if(p->next!=NULL)
    {
        p->next->prior=s;
    }
    s->prior=p;
    p->next=s;
    return true;
}

//删除元素
bool DList_Delete(DLinkList &DL,int i,ElemType &e)
{
    DLNode *p= GetElem(DL,i-1);
    if(NULL==p)
    {
        return false;
    }
    DLNode *q=p->next;
    e=q->data;
    if(NULL==q)
    {
        return false;
    }
    p->next=q->next;
    if(q->next!=NULL)
    {
        q->next->prior = p;
    }
    free(q);
    return true;
}
//链表打印
void PrintDList(DLinkList DL)
{
    DL=DL->next;
    while(DL!=NULL)
    {
        printf("%3d",DL->data);
        DL=DL->next;
    }
    printf("\n");
}

// int main()
// {
//     DLinkList DL;
//     ElemType e;
//     DLink_TailInsert(DL);
//     DLNode *p= GetElem(DL,5);
// //    DList_Insert(DL,5,5);
// //    DList_Insert(DL,2,2);
//     DList_Delete(DL,5,e);
//     return 0;
// }


