#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;

struct SList {
	SLDataType data;
	SList* next;
};

void SListPrint(SList* phead);
void SListPushBack(SList** phead,SLDataType x);
void SListPushFront(SList** phead, SLDataType x);
void SListPopFront(SList** phead);
SList* SListFind(SList* phead, SLDataType x);
void SListInsert(SList** phead,SList*pos, SLDataType x);
void SListErace(SList** phead, SList* pos);
void SListEraceAfter(SList** phead, SList* pos);
void SListReverseK(SList* phead, int k);
void SListReverse(SList* phead);
void sll_insert(SList** phead, SLDataType x);