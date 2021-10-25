#pragma once
#include<stdio.h>
#define OK 1
#define ERROR 0
#define FALSE -1
#define TRUE 0
#define MAXSIZE 20
typedef int ElemType;
typedef struct {
	ElemType data[MAXSIZE];
	int length;
}SqList;
typedef int Status;
SqList Lb;
ElemType e;

Status InitList(SqList *L);//初始化线性表
Status ListEmpty(SqList);//判断线性表是否为空
Status ClearList(SqList *L);//将L置为空表
int Listlength(SqList);//L的元素个数
Status GetElem(SqList L, int i, Status* e);//获取第i个数据的值并用e返回
Status LocatElem(SqList L, ElemType e);//返回某元素在L中的位置
Status ListInsert(SqList *L, int i, ElemType e);//向L中插入一个元素
Status ListDelete(SqList *L, int i, ElemType* e);//删除L中某个元素
Status ListTraverse(SqList L);//输出L的每个元素
void unionL(SqList *La, SqList Lb);//合并La，Lb









