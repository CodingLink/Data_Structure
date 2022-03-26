//
// Created by yoran on 2022/3/24.
//

#ifndef DATA_STRUCTURE_LINKQUEUE_H
#define DATA_STRUCTURE_LINKQUEUE_H


typedef int ElemType;
//链式队列
typedef struct LinkNode {
    ElemType data;//数据域
    struct LinkNode* next;//指针域
}LinkNode;

typedef struct {
    LinkNode* front, * rear;//队头和队尾指针
}LinkQueue;

//初始化链队
void InitQueue(LinkQueue& Q);

//判断队列是否为空
bool isEmpty(LinkQueue Q);

//入队
bool EnQueue(LinkQueue& Q, ElemType e);

//出队
bool DeQueue(LinkQueue& Q, ElemType& e);

#endif //DATA_STRUCTURE_LINKQUEUE_H
