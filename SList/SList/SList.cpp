#include"标头.h"

//打印链表
void SListPrint(SList*phead)
{
	SList* tail = phead;
	while (tail != NULL) {
		printf("%d->", tail->data);
		tail = tail->next;
	}
	printf("NULL\n");
}
//创建节点
SList* BuySListNode(SLDataType x)
{
	SList* newcode = (SList*)malloc(sizeof(SList));
	newcode->data = x;
	newcode->next = NULL;
	return newcode;
}

//尾插
void SListPushBack(SList** phead,SLDataType x) {
	
	SList*newcode=BuySListNode(x);
	//判断
	if (*phead == NULL) {
		*phead = newcode;
	}
	else 
	{
		//找到尾节点
		SList* tail = *phead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newcode;
	}
}

//头插
void SListPushFront(SList** phead, SLDataType x)
{
	SList* newcode = BuySListNode(x);
	newcode->next = *phead;
	*phead = newcode;
}

//头删
void SListPopFront(SList** phead)
{
	if (*phead == NULL)
	{
		return;
	}
	SList* tail = (*phead)->next;
	free(*phead);
	*phead = tail;
}

//尾删
void SListPopBack(SList** phead, SLDataType x)
{
	//找到尾节点
	//1.
	/*if (*phead == NULL)
	{
		return;
	}*/
	//assert(*phead != NULL);
	if ((*phead)->next==NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	else {
		SList* prev = NULL;
		SList* tail = *phead;
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
	//2.
	/*SList* tail = *phead;
	while (tail->next->next)
	{
		tail = tail->next;
	}
	free(tail->next);
	tail = NULL;*/
}

//在链表中寻找元素
SList* SListFind(SList* phead, SLDataType x)
{
	SList* tail = phead;
	while (tail)
	{
		if (tail->data == x)
		{
			return tail;
		}
		else {
			tail = tail->next;
		}
	}
	return NULL;
}

//在链表中插入元素
void SListInsert(SList** phead, SList* pos, SLDataType x) {
	SList* newcode = BuySListNode(x);
	if (*phead != pos)
	{
		SList* posPrev = *phead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}
		posPrev->next = newcode;
		newcode->next = pos;
	}
	else {
		newcode->next = *phead;
		*phead = newcode;
	}
}

//在链表中删除pos位元素
void SListErace(SList** phead, SList* pos)
{
	if (*phead == pos)
	{
		SListPopFront(phead);
	}
	else {
		SList* prev = *phead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//在链表中删除pos后一位的元素
void SListEraceAfter(SList** phead, SList* pos)
{
	SList* next = pos->next;
	pos->next = next->next;
	free(pos);
	pos = NULL;
}

//从链表的倒数第k个数打印链表
void SListReverseK(SList* phead, int k)
{
	/*SList* tail = phead;
	int n = 1;
	while (tail->next)
	{
		tail = tail->next;
		n++;
	}
	SList* cur = phead;
	for (int i = 0; i < n - k; i++)
	{
		cur = cur->next;
	}
	SListPrint(cur);*/
	SList* fast = phead;
	SList* slow = phead;
	while (k > 0)
	{
		fast = fast->next;
		k--;
	}
	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	SListPrint(slow);
}

//反转输出链表
void SListReverse(SList* phead)
{
	SList* tail = phead;
	if (tail == NULL)
	{
		return;
	}
	SListReverse(tail->next);
	printf("%d ", tail->data);
}

//将一个元素插入到一个有序链表
void sll_insert(SList**phead,SLDataType x)
{
	//SList* cur = *phead;
	//SList* prev = NULL;
	//while (cur != NULL && cur->data < x)
	//{
	//	prev = cur;
	//	cur = cur->next;
	//}
	//SList*newcode=BuySListNode(x);
	//newcode->next = cur;
	//if (prev == NULL)//避免对空指针进行访问操作
	//{
	//	*phead = newcode;
	//}
	//else {
	//	prev->next = newcode;
	//}

	SList* cur;
	while ((cur = *phead) != NULL && cur->data < x)
	{
		phead = &cur->next;
	}
	SList* newcode = BuySListNode(x);
	newcode->next = cur;
	*phead = newcode;
}