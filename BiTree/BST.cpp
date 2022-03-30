//
// Created by yoran on 2022/3/27.
//二叉排序树
#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;

typedef struct BSTNode{
    KeyType key;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BiTree;

//插入新结点
int BST_Insert(BiTree &T,KeyType k) {
    //如果树为空，创建新树
    if (NULL == T) {
        T = (BiTree) malloc(sizeof(BiTree));
        T->key = k;
        T->lchild = T->rchild = NULL;
    }
    if (k == T->key) {
        return 0;//相同元素，不插入
    } else if (k < T->key) {
        BST_Insert(T->lchild, k);
    } else {
        BST_Insert(T->rchild, k);
    }
    return 1;
}

//创建二叉排序树
int CreateBST(BiTree &T,KeyType str[],int n)
{
    T=NULL;
    int i=0;
    while(i<n)
    {
        BST_Insert(T,str[i]);
        i++;
    }
    return 1;
}

//中序遍历
void InOrder(BiTree T)
{
    if(NULL!=T)
    {
        InOrder(T->lchild);
        printf("%4d",T->key);
        InOrder(T->rchild);
    }
}

//非递归查找结点
//返回值为要找到的结点
//p为其父亲结点
BSTNode* BST_Search(BiTree T,KeyType k,BiTree &p)
{
    p=NULL;
    while(NULL!=T&&k!=T->key)
    {
        p=T;
        if(k<T->key)
        {
            T=T->lchild;
        }else{
            T=T->rchild;
        }
    }
    return T;
}

//递归查找结点（效率较低）
BSTNode* BST_Search2(BiTree T,KeyType k)
{
    if(NULL!=T&&k==T->key)
    {
        return T;
    }
    else if(k<T->key)
    {
        return BST_Search2(T->lchild,k);
    }
    else
    {
        return BST_Search2(T->rchild,k);
    }
}

//删除结点
void DeleteNode(BiTree &T,KeyType k)
{
    //当树为空时，退出
    if(NULL==T)
    {
        return;
    }
    if(k<T->key)
    {
        DeleteNode(T->lchild,k);
    }
    else if(k>T->key)
    {
        DeleteNode(T->rchild,k);
    }else{
        //当左子树为空
        if(NULL==T->lchild)
        {
            BiTree tempNode=T;
            T=T->rchild;
            free(tempNode);
        }
        //当右子树为空
        else if(NULL==T->rchild)
        {
            BiTree tempNode=T;
            T=T->lchild;
            free(tempNode);
        }else{
            //左右子树都不为空
            //选择左子树最右边结点（或右子树最左结点）代替要删除的结点
            BiTree tempNode=T->lchild;
            if(NULL!=tempNode->rchild)
            {
                tempNode=tempNode->rchild;
            }
            T->key=tempNode->key;
            DeleteNode(T->lchild,tempNode->key);
        }
    }
}
//int main()
//{
//    BiTree T,p=NULL;
//    KeyType str[]={54,20,66,40,28,79,58};
//    CreateBST(T,str,7);
//    InOrder(T);
//    BiTree t1=BST_Search(T,28,p);
//    BiTree t2= BST_Search2(T,28);
//    DeleteNode(T,54);
//    printf("\n");
//    InOrder(T);
//    return 0;
//}