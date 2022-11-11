#include "��ͷ.h"

//���г�ʼ��
void QueneInit(Quene* ps)
{
	ps->head = NULL;
	ps->tail = NULL;
}

//���ٶ���
void QueneNodeDestroy(Quene* ps)
{
	assert(ps);
	QueneNode* cur = ps->head;
	while (cur != NULL) {
		QueneNode* next = cur->next;
		free(cur);
		cur = next;
	}
}

//����Ԫ��
void QuenePush(Quene* ps, int data)
{
	assert(ps);
	QueneNode* newcode = (QueneNode*)malloc(sizeof(QueneNode));
	if (ps->tail != NULL)
	{
		ps->tail->next = newcode;
		ps->tail = newcode;
	}
	else {
		ps->tail = newcode;
		ps->head = newcode;
	}
	newcode->data = data;
}

//ɾ��Ԫ��
void QuenePop(Quene* ps)
{
	assert(ps);
	assert(!QueneEmpty(ps));
	QueneNode* cur = ps->head;
	free(ps->head);
	ps->head = cur->next;//ֻд��Щ�����Ұָ��
	if (ps->head == NULL)
	{
		ps->tail = NULL;
	}
}

//�ж϶����Ƿ�Ϊ��
bool QueneEmpty(Quene* ps)
{
	assert(ps);
	return ps->head == NULL;
}

//�����ͷ��Ԫ��
int QueneFront(Quene* ps)
{
	assert(ps);
	return ps->head->data;
}

//�����β��Ԫ��
int QueneBack(Quene* ps)
{
	assert(ps);
	return ps->tail->data;
}

//������еĳ���
int QueneSize(Quene* ps)
{
	int size = 0;
	QueneNode* cur = ps->head;
	while (cur)
	{
		++size;
		cur = cur->next;
	}
	return size;
}

//��ʼ��ջ
MyStack* MyStackCreat()
{
	MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
	QueneInit(stack->q1);
	QueneInit(stack->q2);
	return stack;
}

//Ԫ�ؽ�ջ
MyStack* MystackPush(MyStack* stack, int data)
{
	if (!QueneEmpty(stack->q1)) {
		QuenePush(stack->q1, data);
	}
	else {
		QuenePush(stack->q2, data);
	}
}

//ջ��ɾ��Ԫ��
int MyStackPop(MyStack* stack)
{
	Quene* noneemptyqQ = stack->q1;
	Quene* emptyQ = stack->q2;
	if (!QueneEmpty(stack->q1)) {
		noneemptyqQ = stack->q2;
		emptyQ = stack->q2;
	}
	while (QueneSize(noneemptyqQ) > 1)
	{
		QuenePush(emptyQ, QueneFront(noneemptyqQ));
		QuenePop(noneemptyqQ);
	}
	int pop = QueneFront(noneemptyqQ);
	QuenePop(noneemptyqQ);
	return pop;
}

//ȡ��ջ����Ԫ��
int MyStackTop(MyStack* stack)
{
	if (!QueneEmpty(stack->q1))
	{
		return QueneBack(stack->q1);
	}
	else {
		return QueneBack(stack->q2);
	}
}

bool MyStackEmpty(MyStack* stack)
{
	return QueneEmpty(stack->q1) && QueneEmpty(stack->q2);
}

void MyStackDestroy(MyStack* stack)
{
	//���ֻ��free����̬�����ڴ�����stack�ṹ��stack��ָ��������ᱻ�ͷ�
	QueneNodeDestroy(stack->q1);
	QueneNodeDestroy(stack->q2);
	free(stack);
}