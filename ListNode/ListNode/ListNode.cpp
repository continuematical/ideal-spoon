#include "��ͷ.h"
//�����ʼ��
ListNode* ListNodeInit()
{
	ListNode* phead = (ListNode*)malloc(sizeof(ListNode));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
//����һ������
ListNode* BuyListNode()
{
	ListNode* newcode = (ListNode*)malloc(sizeof(ListNode));
	newcode->next = NULL;
	newcode->prev = NULL;
	return newcode;
}
//β��
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
//��ӡ����
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
//βɾ
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
//ͷɾ
void ListNodePopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	ListNode* tail = phead->next;
	phead->next = tail->next;
	tail->next->prev = phead;
}
//ͷ��
void ListNodePushFront(ListNode* phead,LTDataType x)
{
	ListNode* tail = BuyListNode();
	tail->next = phead->next;
	phead->next = tail;
	tail->prev = phead;
	tail->data = x;
}
//��posλ��ǰ����һ���ڵ�
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
//ɾ��posλ�õĽڵ�
void ListErace(ListNode* pos)
{
	ListNode* posprev = pos->prev;
	ListNode* posnext = pos->next;
	posprev->next = posnext;
	posnext->prev = posprev;
	free(pos);
}
//�������
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