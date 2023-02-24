#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;//数组
	SLDataType size;//数组中存放了多少个元素
	SLDataType capacity;//数组的容量
}SL;
//新定义的结构体类型标识符

//接口函数
void SeqListInit(SL* ps);
void SeqListPrint(SL* ps);
void SeqListDestroy(SL* ps);
void SeqListCheckCapacity(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);