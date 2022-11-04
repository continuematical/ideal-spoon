#include "标头.h"
//链表初始化
ListNode* ListNodeInit()
{
	ListNode* phead = (ListNode*)malloc(sizeof(ListNode));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
//创建一个链表
ListNode* BuyListNode()
{
	ListNode* newcode = (ListNode*)malloc(sizeof(ListNode));
	newcode->next = NULL;
	newcode->prev = NULL;
	return newcode;
}
//尾插
void ListNodePushBack(ListNode* phead,LTDataType x)
{
	assert(phead);
	ListNode* tail = phead->prev;
	ListNode* newcode = BuyListNode();
	newcode->data = x;
	tail->next = newcode;
	newcode->prev = tail;
	newcode->next = phead;
	phead->prev = newcode;
}
//打印链表
void ListPrint(ListNode* phead)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
//尾删
void ListNodePopBack(ListNode* phead)
{
	assert(phead != NULL);
	assert(phead->next != phead);
	ListNode* cur = phead->prev;
	if (cur == NULL)
	{
		return;
	}
	cur->prev->next = phead;
	phead->prev = cur->prev;
	free(cur);
}
//头删
void ListNodePopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	ListNode* tail = phead->next;
	phead->next = tail->next;
	tail->next->prev = phead;
}
//头插
void ListNodePushFront(ListNode* phead,LTDataType x)
{
	ListNode* tail = BuyListNode();
	tail->next = phead->next;
	phead->next = tail;
	tail->prev = phead;
	tail->data = x;
}
//在pos位置前插入一个节点
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* plist = BuyListNode();
	plist->data = x;
	ListNode* posprev = pos->prev;
	posprev->next = plist;
	plist->prev = posprev;
	plist->next = pos;
	pos->prev = plist;
}
//删除pos位置的节点
void ListErace(ListNode* pos)
{
	ListNode* posprev = pos->prev;
	ListNode* posnext = pos->next;
	posprev->next = posnext;
	posnext->prev = posprev;
	free(pos);
}
//清除链表
void ListDestroy(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		free(cur->next);
		cur = cur->next;
	}
	free(phead);
}