#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDataType;

struct ListNode
{
	LTDataType data;
	ListNode* prev;
	ListNode* next;
};

ListNode* ListNodeInit();
void ListNodePushBack(ListNode* phead,LTDataType x);
void ListNodePushFront(ListNode* phead, LTDataType x);
void ListNodePopBack(ListNode* phead);
void ListNodePopFront(ListNode* phead);
void ListPrint(ListNode* phead);
ListNode* BuyListNode();
void ListInsert(ListNode* pos, LTDataType x);
void ListErace(ListNode* pos);
void ListDestroy(ListNode* phead);