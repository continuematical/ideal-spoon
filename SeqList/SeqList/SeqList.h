#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;//����
	SLDataType size;//�����д���˶��ٸ�Ԫ��
	SLDataType capacity;//���������
}SL;
//�¶���Ľṹ�����ͱ�ʶ��

//�ӿں���
void SeqListInit(SL* ps);
void SeqListPrint(SL* ps);
void SeqListDestroy(SL* ps);
void SeqListCheckCapacity(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);