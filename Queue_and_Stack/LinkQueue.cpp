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

//入队,队尾插入法
bool EnQueue(LinkQueue& Q, ElemType e)
{
    LinkNode* s;
    s = (LinkNode*)calloc(1, sizeof(LinkNode));
    s->data = e;//插入数据
    s->next = NULL;//插入的是队尾
    Q.rear->next = s;//队尾指针指向新节点
    Q.rear = s;//队尾指针后移
    return true;
}

//出队，队首删除法
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
    //如果队列只有一个元素，那么队尾指针也要指向NULL
    if (Q.rear == p)
    {
        Q.rear = Q.front;
    }
    free(p);
    return true;
}
