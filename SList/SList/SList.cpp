#include"��ͷ.h"

//��ӡ����
void SListPrint(SList*phead)
{
	SList* tail = phead;
	while (tail != NULL) {
		printf("%d->", tail->data);
		tail = tail->next;
	}
	printf("NULL\n");
}
//�����ڵ�
SList* BuySListNode(SLDataType x)
{
	SList* newcode = (SList*)malloc(sizeof(SList));
	newcode->data = x;
	newcode->next = NULL;
	return newcode;
}

//β��
void SListPushBack(SList** phead,SLDataType x) {
	
	SList*newcode=BuySListNode(x);
	//�ж�
	if (*phead == NULL) {
		*phead = newcode;
	}
	else 
	{
		//�ҵ�β�ڵ�
		SList* tail = *phead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newcode;
	}
}

//ͷ��
void SListPushFront(SList** phead, SLDataType x)
{
	SList* newcode = BuySListNode(x);
	newcode->next = *phead;
	*phead = newcode;
}

//ͷɾ
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

//βɾ
void SListPopBack(SList** phead, SLDataType x)
{
	//�ҵ�β�ڵ�
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

//��������Ѱ��Ԫ��
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

//�������в���Ԫ��
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

//��������ɾ��posλԪ��
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

//��������ɾ��pos��һλ��Ԫ��
void SListEraceAfter(SList** phead, SList* pos)
{
	SList* next = pos->next;
	pos->next = next->next;
	free(pos);
	pos = NULL;
}

//������ĵ�����k������ӡ����
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

//��ת�������
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

//��һ��Ԫ�ز��뵽һ����������
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
	//if (prev == NULL)//����Կ�ָ����з��ʲ���
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