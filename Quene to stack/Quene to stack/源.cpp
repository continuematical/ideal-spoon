#include "标头.h"

//队列初始化
void QueneInit(Quene* ps)
{
	ps->head = NULL;
	ps->tail = NULL;
}

//销毁队列
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

//插入元素
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

//删除元素
void QuenePop(Quene* ps)
{
	assert(ps);
	assert(!QueneEmpty(ps));
	QueneNode* cur = ps->head;
	free(ps->head);
	ps->head = cur->next;//只写这些会产生野指针
	if (ps->head == NULL)
	{
		ps->tail = NULL;
	}
}

//判断队列是否为空
bool QueneEmpty(Quene* ps)
{
	assert(ps);
	return ps->head == NULL;
}

//输出队头的元素
int QueneFront(Quene* ps)
{
	assert(ps);
	return ps->head->data;
}

//输出队尾的元素
int QueneBack(Quene* ps)
{
	assert(ps);
	return ps->tail->data;
}

//输出队列的长度
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

//初始化栈
MyStack* MyStackCreat()
{
	MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
	QueneInit(stack->q1);
	QueneInit(stack->q2);
	return stack;
}

//元素进栈
MyStack* MystackPush(MyStack* stack, int data)
{
	if (!QueneEmpty(stack->q1)) {
		QuenePush(stack->q1, data);
	}
	else {
		QuenePush(stack->q2, data);
	}
}

//栈：删除元素
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

//取出栈顶的元素
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
	//如果只是free掉动态分配内存分配的stack结构，stack内指向的链表不会被释放
	QueneNodeDestroy(stack->q1);
	QueneNodeDestroy(stack->q2);
	free(stack);
}