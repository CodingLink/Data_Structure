//
// Created by yoran on 2022/3/24.
//

#ifndef DATA_STRUCTURE_LINKQUEUE_H
#define DATA_STRUCTURE_LINKQUEUE_H


typedef int ElemType;

typedef struct LinkNode {
    ElemType data;
    struct LinkNode* next;
}LinkNode;

typedef struct {
    LinkNode* front, * rear;
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
