//
// Created by yoran on 2022/3/24.
//

#include<iostream>
#include "function.h"

typedef char ElemType;


//�ݹ�ǰ�����
void PreOrder(BiTree P)
{
    if (P != NULL)
    {
        putchar(P->data);
        PreOrder(P->lchild);
        PreOrder(P->rchild);
    }
}

//�ݹ��������
void InOrder(BiTree P)
{
    if (P != NULL)
    {
        InOrder(P->lchild);
        putchar(P->data);
        InOrder(P->rchild);
    }
}

//�ݹ�������
void PostOrder(BiTree P)
{
    if (P != NULL)
    {
        PostOrder(P->lchild);
        PostOrder(P->rchild);
        putchar(P->data);
    }
}

//���򣨲�Σ������ǵݹ�
void LevelOrder(BiTree P)
{
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q, P);
    ElemType e;
    while (!isEmpty(Q))
    {
        DeQueue(Q, P);
        putchar(P->data);
        if (P->lchild != NULL)
        {
            EnQueue(Q, P->lchild);
        }
        if (P->rchild != NULL)
        {
            EnQueue(Q, P->rchild);
        }
    }

}
int main()
{
    BiTree pnew;
    //LinkQueue p;
    //InitQueue(p);
    ElemType c;
    BiTree tree=NULL; //����
    ptag_t phead = NULL, ptail = NULL, listpnew, pcur;//phead�Ƕ���ͷ��ptail�Ƕ���β��listnew��������ʱ��Ŷ��н��
    pcur = phead;
    while (scanf("%c", &c) != EOF)
    {
        if ('\n' == c)
        {
            break;
        }
        pnew = (BiTree)calloc(1, sizeof(BiTNode));
        pnew->data = c;
        listpnew = (ptag_t)calloc(1, sizeof(tag_t));
        listpnew->p = pnew;
        if (tree == NULL)
        {
            tree = pnew;
            phead = listpnew;//����ͷ
            ptail = listpnew;//����β
            pcur = listpnew;
            continue;
        }else{
            ptail->pnext = listpnew;//�½��ͨ��β�巨����
            ptail = listpnew;
            if (NULL == pcur->p->lchild)
            {
                pcur->p->lchild = pnew;
            }
            else if(NULL==pcur->p->rchild) {
                pcur->p->rchild = pnew;
                pcur = pcur->pnext;
            }
        }
    }
    printf("-------------------ǰ��������--------------------------\n");
    PreOrder(tree);
    printf("\n");
    printf("-------------------����������--------------------------\n");
    InOrder(tree);
    printf("\n");
    printf("-------------------����������--------------------------\n");
    PostOrder(tree);
    printf("\n");
    printf("-------------------����������--------------------------\n");
    LevelOrder(tree);
    printf("\n");
}

