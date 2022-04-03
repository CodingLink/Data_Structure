//
// Created by yoran on 2022/4/1.
// 冒泡排序和快速排序
#include <stdio.h>
#include <time.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
typedef int ElemType;

typedef struct {
    ElemType *elem;
    int TableLen;
}SSTable;

//生成随机数
void ST_Init(SSTable &ST,int n)
{
    ST.TableLen=n;
    ST.elem=(ElemType*) malloc(sizeof (ElemType)*ST.TableLen);
    srand(time(NULL));
    for(int i=0;i<ST.TableLen;i++)
    {
        ST.elem[i]=rand()%100;
    }
}

//打印数组
void printList(SSTable ST)
{
    for(int i=0;i<ST.TableLen;i++)
    {
        printf("%3d",ST.elem[i]);
    }
    printf("\n");
}

//交换函数
void Swap(ElemType &a,ElemType &b)
{
    ElemType temp;
    temp=a;
    a=b;
    b=temp;

}

//冒泡排序
void BubbleSort(ElemType A[],int n)
{
    int i,j;
    bool flag;
    for(i=0;i<n-1;i++)
    {
        flag= false;
        for(j=n-1;j>i;j--)
        {
            if(A[j]<A[j-1])
            {
                Swap(A[j], A[j - 1]);
                flag= true;
            }
        }
        if(flag== false)
            return;
    }
}


//快速排序
int Partition(int *arr,int left,int right)
{
    int k,i;//k记录最左端的值
    for(k=left,i=left;i<right;i++)
    {
        if(arr[i]<arr[right]) {
            Swap(arr[i], arr[k]);
            k++;
        }
    }
    Swap(arr[k],arr[right]);
    return k;
}

void QuickSort(ElemType A[],int low,int high)
{
    if(low<high)
    {
        int p= Partition(A,low,high);
        QuickSort(A,low,p-1);
        QuickSort(A,p+1,high);
    }
}

//int main()
//{
//    ElemType A[10]={ 64, 94, 95, 79, 69, 84, 18, 22, 12 ,78};
//    SSTable ST;
//    ST_Init(ST,10);
//    printList(ST);
////    memcpy(ST.elem,A,sizeof(A));
////    BubbleSort(ST.elem,10);
//    QuickSort(ST.elem,0,9);
//    printList(ST);
//    return 0;
//}


