//
// Created by yoran on 2022/3/24.
//

#ifndef DATA_STRUCTURE_FUNCTION_H
#define DATA_STRUCTURE_FUNCTION_H

//与二叉树有关的数据结构

typedef struct BiTNode {
    char data;
    struct BiTNode* lchild, * rchild;
} BiTNode, * BiTree;

typedef struct tag {
    BiTree p;
    struct tag* pnext;
}tag_t, * ptag_t;

void PreOrder(BiTree P);
void InOrder(BiTree P);
void PostOrder(BiTree P);
void LevelOrder(BiTree P);

//与队列有关的数据结构


typedef struct LinkNode {
    BiTree data;
    struct LinkNode* next;
}LinkNode;

typedef struct {
    LinkNode* front, * rear;
}LinkQueue;


void InitQueue(LinkQueue& Q);
bool isEmpty(LinkQueue Q);
bool EnQueue(LinkQueue& Q, BiTree e);
bool DeQueue(LinkQueue& Q, BiTree& e);

#endif //DATA_STRUCTURE_FUNCTION_H
