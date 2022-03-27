//
// Created by yoran on 2022/3/24.
//

#include<iostream>
#include "function.h"

typedef char ElemType;


//�ݹ�ǰ�����
void PreOrder(BiTree T)
{
    if (T != NULL)
    {
        putchar(T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

//�ݹ��������
void InOrder(BiTree T)
{
    if (T != NULL)
    {
        InOrder(T->lchild);
        putchar(T->data);
        InOrder(T->rchild);
    }
}

//�ݹ�������
void PostOrder(BiTree T)
{
    if (T != NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        putchar(T->data);
    }
}

//���򣨲�Σ������ǵݹ�
void LevelOrder(BiTree T)
{
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q, T);//�������
    BiTree P;
    while (!isEmpty(Q))
    {
        DeQueue(Q, P);//��ͷ����
        putchar(P->data);//�����ͷԪ��
        if (P->lchild != NULL)
        {
            EnQueue(Q, P->lchild);//�������
        }
        if (P->rchild != NULL)
        {
            EnQueue(Q, P->rchild);//�Һ������
        }
    }

}
//int main()
//{
//    BiTree pnew;
//    ElemType c;
//    BiTree tree=NULL; //����
//    ptag_t phead = NULL, ptail = NULL, listpnew, pcur;//phead�Ƕ���ͷ��ptail�Ƕ���β��listnew��������ʱ��Ŷ��н��
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
//            phead = listpnew;//����ͷ
//            ptail = listpnew;//����β
//            pcur = listpnew;
//            continue;
//        } else {
//            ptail->pnext = listpnew;//�½��ͨ��β�巨����
//            ptail = listpnew;
//            if (NULL == pcur->p->lchild) {
//                pcur->p->lchild = pnew;
//            } else if (NULL == pcur->p->rchild) {
//                pcur->p->rchild = pnew;
//                pcur = pcur->pnext;
//            }
//        }
//    }
//    printf("-------------------ǰ��������--------------------------\n");
//    PreOrder(tree);
//    printf("\n");
//    printf("-------------------����������--------------------------\n");
//    InOrder(tree);
//    printf("\n");
//    printf("-------------------����������--------------------------\n");
//    PostOrder(tree);
//    printf("\n");
//    printf("-------------------����������--------------------------\n");
//    LevelOrder(tree);
//    printf("\n");
//}

