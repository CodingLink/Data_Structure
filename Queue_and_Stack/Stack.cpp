//
// Created by yoran on 2022/3/24.
//

#include<iostream>
#define MaxSize 50
typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int top;
}SqStack;

//初始化栈
void InitStack(SqStack& S)
{
    S.top = -1;
}

//判断栈空
bool StackEmpty(SqStack S)
{
    if (S.top = -1)
    {
        return true;
    }
    return false;
}

//进栈
bool Push(SqStack& S, ElemType e)
{
    if (S.top == MaxSize - 1)
    {
        return false;
    }
    S.data[++S.top] = e;
    return true;
}

//出栈
bool Pop(SqStack& S, ElemType& e)
{
    if (S.top == -1)
    {
        return false;
    }
    e = S.data[S.top--];
    return true;
}

//读取栈顶元素
bool GetTop(SqStack S, ElemType& e)
{
    if (S.top == -1)
    {
        return false;
    }
    e = S.data[S.top];
    return true;
}

//int main()
//{
//    SqStack S;
//    ElemType e;
//    InitStack(S);
//    Push(S, 1);
//    Push(S, 2);
//    Push(S, 3);
//    Push(S, 4);
//    Pop(S, e);
//    Pop(S, e);
//    GetTop(S, e);
//}