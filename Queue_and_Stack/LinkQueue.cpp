//
// Created by yoran on 2022/3/24.
//

#include "LinkQueue.h"

#include <iostream>

//初始化链队
void InitQueue(LinkQueue& Q)
{
    Q.front = Q.rear = (LinkNode*)calloc(1, sizeof(LinkNode));
    Q.front->next = NULL;
}

//判断队列是否为空
bool isEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear)
    {
        return true;
    }
    return false;
}

//入队
bool EnQueue(LinkQueue& Q, ElemType e)
{
    LinkNode* s;
    s = (LinkNode*)calloc(1, sizeof(LinkNode));
    s->data = e;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
    return true;
}

//出队
bool DeQueue(LinkQueue& Q, ElemType& e)
{
    if (isEmpty(Q))
    {
        return false;
    }
    LinkNode* p;
    p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
    {
        Q.rear = Q.front;
    }
    free(p);
    return true;
}
