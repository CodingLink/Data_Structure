//
// Created by yoran on 2022/3/24.
//

#ifndef DATA_STRUCTURE_SQQUEUE_H
#define DATA_STRUCTURE_SQQUEUE_H


#define MaxSize 50
typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int front, rear;
}SqQueue;

//初始化队列
void InitQueue(SqQueue& Q);

//判断队空
bool QueueEmpty(SqQueue Q);

//入队
bool EnQueue(SqQueue& Q,ElemType e);

//出队
bool DeQueue(SqQueue& Q, ElemType& e);

#endif //DATA_STRUCTURE_SQQUEUE_H
