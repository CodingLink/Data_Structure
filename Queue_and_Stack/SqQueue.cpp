//
// Created by yoran on 2022/3/24.
//

#include "SqQueue.h"
#include<iostream>

//初始化队列
void InitQueue(SqQueue& Q)
{
    Q.front = Q.rear = 0;
}

//判断队空
bool QueueEmpty(SqQueue Q)
{
    if (Q.front == Q.rear)
    {
        return true;
    }
    return false;
}

//入队
bool EnQueue(SqQueue& Q,ElemType e)
{
    //队满
    if ((Q.rear+1)%MaxSize == Q.front)
    {
        return false;
    }
    //入队
    Q.data[Q.rear] = e;
    //更新队尾
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

//出队
bool DeQueue(SqQueue& Q, ElemType& e)
{
    //队空
    if (QueueEmpty(Q))
    {
        return false;
    }
    //队首元素
    e = Q.data[Q.front];
    //更新队头
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}


