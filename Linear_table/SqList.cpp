//
// Created by yoran on 2022/3/31.
// 顺序表
#include <stdio.h>
#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int len;
}SqList;

//初始化顺序表
void InitSqList(SqList &L)
{
    L.len=0;
}

//按值查找
int LocateElem(SqList L,ElemType e)
{
    int i=0;
    for(i;i<L.len;i++)
    {
        if(L.data[i]==e)
        {
            return i+1;
        }
    }
    return 0;
}

//按位查找
ElemType GetElem(SqList L,int i)
{
    if(i<1||i>L.len)
    {
        return NULL;
    }
    return L.data[i-1];
}

//插入元素
bool ListInsert(SqList &L,int i,ElemType e)
{
    if(i<1||i>L.len+1)
    {
        return false;
    }
    int j;
    for(j=L.len;j>=i;j--)
    {
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.len++;
    return true;
}

//删除元素
bool ListDelete(SqList &L,int i,ElemType &e)
{
    if(i<1||i>L.len)
    {
        return false;
    }
    if(L.len==0)
    {
        return false;
    }
    e=L.data[i-1];
    for(int j=i;j<L.len;j++)
    {
        L.data[j-1]=L.data[j];
    }
    L.len--;
    return true;
}

//int main()
//{
//    ElemType e;
//    SqList L;
//    InitSqList(L);
//    ListInsert(L,1,1);
//    ListInsert(L,2,3);
//    ListInsert(L,3,4);
//    ListInsert(L,4,5);
//    ListInsert(L,2,2);
//    ListDelete(L,4,e);
//    return 0;
//}

