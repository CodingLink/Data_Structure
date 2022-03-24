//
// Created by yoran on 2022/3/24.
//

#ifndef DATA_STRUCTURE_SQLIST_H
#define DATA_STRUCTURE_SQLIST_H

#define MaxSize 50
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int length;
}SqList;

bool InitList(SqList& L);

//求表长
int Length(SqList L);

//按值查找元素
int LocateElem(SqList L, ElemType e);

//插入元素
bool ListInsert(SqList& L, int i, ElemType e);

bool ListDelete(SqList& L, int i, ElemType& e);

#endif //DATA_STRUCTURE_SQLIST_H
