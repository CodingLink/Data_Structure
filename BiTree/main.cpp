//
// Created by yoran on 2022/3/24.
//

#include<iostream>
#include "function.h"

typedef char ElemType;


//递归前序遍历
void PreOrder(BiTree T)
{
    if (T != NULL)
    {
        putchar(T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

//递归中序遍历
void InOrder(BiTree T)
{
    if (T != NULL)
    {
        InOrder(T->lchild);
        putchar(T->data);
        InOrder(T->rchild);
    }
}

//递归后序遍历
void PostOrder(BiTree T)
{
    if (T != NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        putchar(T->data);
    }
}

//层序（层次）遍历非递归
void LevelOrder(BiTree T)
{
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q, T);//树根入队
    BiTree P;
    while (!isEmpty(Q))
    {
        DeQueue(Q, P);//队头出队
        putchar(P->data);//输出队头元素
        if (P->lchild != NULL)
        {
            EnQueue(Q, P->lchild);//左孩子入队
        }
        if (P->rchild != NULL)
        {
            EnQueue(Q, P->rchild);//右孩子入队
        }
    }

}
//int main()
//{
//    BiTree pnew;
//    ElemType c;
//    BiTree tree=NULL; //树根
//    ptag_t phead = NULL, ptail = NULL, listpnew, pcur;//phead是队列头，ptail是队列尾，listnew是用来临时存放队列结点
//    pcur = phead;
//    while (scanf("%c", &c) != EOF) {
//        if ('\n' == c) {
//            break;
//        }
//        pnew = (BiTree) calloc(1, sizeof(BiTNode));
//        pnew->data = c;
//        listpnew = (ptag_t) calloc(1, sizeof(tag_t));
//        listpnew->p = pnew;
//        if (tree == NULL) {
//            tree = pnew;
//            phead = listpnew;//队列头
//            ptail = listpnew;//队列尾
//            pcur = listpnew;
//            continue;
//        } else {
//            ptail->pnext = listpnew;//新结点通过尾插法插入
//            ptail = listpnew;
//            if (NULL == pcur->p->lchild) {
//                pcur->p->lchild = pnew;
//            } else if (NULL == pcur->p->rchild) {
//                pcur->p->rchild = pnew;
//                pcur = pcur->pnext;
//            }
//        }
//    }
//    printf("-------------------前序遍历结果--------------------------\n");
//    PreOrder(tree);
//    printf("\n");
//    printf("-------------------中序遍历结果--------------------------\n");
//    InOrder(tree);
//    printf("\n");
//    printf("-------------------后序遍历结果--------------------------\n");
//    PostOrder(tree);
//    printf("\n");
//    printf("-------------------层序遍历结果--------------------------\n");
//    LevelOrder(tree);
//    printf("\n");
//}

