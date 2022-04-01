//
// Created by yoran on 2022/3/30.
// 快速查找和二分查找

#include<stdlib.h>
#include<stdio.h>
#include <ctime>

typedef int ElemType;

typedef struct {
    ElemType *data;//存储数据
    int TableLen;//存储长度
}SSTable;

//init进行了随机数生成
void ST_Init(SSTable &ST,int len)
{
    ST.TableLen=len+1;//多申请了一个位置,为了存哨兵
    //ST.TableLen=len;
    ST.data=(ElemType *)malloc(sizeof(ElemType)*ST.TableLen);
    int i;
    srand(time(NULL));//随机数生成
    for(i=0;i<ST.TableLen;i++)//为啥这里零号位置也随机了数据，为折半查找服务
    {
        ST.data[i]=rand()%100;
    }
}

int Seq_Search(SSTable ST,ElemType e)
{
    ST.data[0]=e;//将e存入哨兵
    int i;
    for(i=ST.TableLen;ST.data[i]!=e;i--);
    return i;
}

void ST_Print(SSTable ST)
{
    for(int i=0;i<ST.TableLen;i++)
    {
        printf("%3d",ST.data[i]);
    }
    printf("\n");
}

int compare(const void *left,const void *right)
{
    return *(ElemType*)left-*(ElemType*)right;
}

//二分查找
int BinarySearch(SSTable ST,ElemType e)
{
    int low=0,high=ST.TableLen-1,mid;
    while(low<=high) {
        mid=(high+low)/2;
        if (ST.data[mid] == e) {
            return mid;
        } else if (ST.data[mid] > e) {
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    return -1;
}

//int main()
//{
//    SSTable ST;
//    ST_Init(ST,10);
//    qsort(ST.data,ST.TableLen,sizeof(ElemType),compare);
//    ST_Print(ST);
//    ElemType e;
//    scanf("%d",&e);
////    printf("%d\n",Seq_Search(ST,e)); //顺序查找
//    printf("%d\n",BinarySearch(ST,e));
//    //ST_Print(ST);
//
//    return 0;
//}
