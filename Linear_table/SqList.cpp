//
// Created by yoran on 2022/3/24.
//顺序表

#include <iostream>
#define MaxSize 50
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int length;
}SqList;

bool InitList(SqList& L)
{
    L.length = 0;
    return true;
}

//求表长
int Length(SqList L) {
    return L.length;
}

//按值查找元素
int LocateElem(SqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            return i + 1;
    }
    return 0;
}

//插入元素
bool ListInsert(SqList& L, int i, ElemType e)
{
    if (i<1 || i>L.length + 1)
    {
        return false;
    }
    if (L.length >= MaxSize)//元素存储满了，不能再存了
    {
        return false;
    }
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList& L, int i, ElemType& e) {
    if (i<1 || i>L.length + 1)
    {
        return false;
    }
    e = L.data[i - 1];
    for (int j = i - 1; j < L.length - 1; j++)
    {
        L.data[j] = L.data[j + 1];
    }
    L.length--;
    return true;
}

//打印顺序表元素
void PrintList(SqList& L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%3d", L.data[i]);//要求所有元素打印到一排
    }
    printf("\n");
}

//int main() {
//    SqList L;
//    ElemType e;
//    InitList(L);
//    ListInsert(L, 1, 1);
//    ListInsert(L, 2, 2);
//    ListInsert(L, 3, 3);
//    ListInsert(L, 2, 100);
//    ListDelete(L, 2,e);
//    return 0;
//}