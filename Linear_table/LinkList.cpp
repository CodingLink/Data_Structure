#include<stdio.h>
#include <malloc.h>
typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//头插法创建单链表
void List_HeadInsert(LinkList &L)
{
    L=(LinkList)malloc(sizeof(LinkList));
    L->next=NULL;
    L->data=NULL;
    LNode *s;
    int x;
    scanf("%d",&x);
    while(x!=9999)
    {
        s=(LNode*) malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
}

//尾插法创建单链表
void List_TailInsert(LinkList &L)
{
    L=(LinkList) malloc(sizeof (LinkList));
    L->next=NULL;
    L->data=NULL;
    LNode *s,*r=L;
    int x;
    scanf("%d",&x);
    while(x!=9999)
    {
        s=(LNode*) malloc(sizeof (LNode));
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;
}

//求表长
int Length(LinkList L)
{
    L=L->next;
    int i=1;
    while(L->next!=NULL)
    {
        L=L->next;
        i++;
    }
    return i;
}

//按值查找
LNode *LocateElem(LinkList L,ElemType e)
{
    LNode *p=L->next;
    while(p!=NULL&&p->data!=e)
    {
        p=p->next;
    }
    return p;
}

//按位查找
LNode *GetElem(LinkList L,int i)
{
    LNode *p=L->next;
    int j=1;
    while(p!=NULL&&j<i)
    {
        p=p->next;
        j++;
    }
    return p;
}

//前插结点
bool ListInsert(LinkList &L,int i,ElemType e)
{
    LNode *p=GetElem(L,i-1);
    if(NULL==p)
    {
        return false;
    }
    LNode *s;
    s=(LNode*) malloc(sizeof (LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}

//删除结点
bool List_Delete(LinkList &L,int i,ElemType &e)
{
    LNode *p= GetElem(L,i-1);
    if(NULL==p)
    {
        return false;
    }
    LNode *q=p->next;
    if(NULL==q)
    {
        return false;
    }
    e=q->data;
    p->next=q->next;
    free(q);
    return true;
}
// int main()
// {
//     LinkList L;
//     ElemType e;
// //    List_HeadInsert(L);
//     List_TailInsert(L);
//     int len=Length(L);
//     LNode *p= GetElem(L,1);
//     ListInsert(L,3,100);
//     len= Length(L);
//     List_Delete(L,3,e);
//     return 0;
// }
