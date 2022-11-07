#include "stack.h"
//��ʼ��
void stackInit(stack* ps)
{
	assert(ps != NULL);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}
//����һ��Ԫ��
void stackPush(stack* ps, int data)
{
	assert(ps != NULL);
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		int* tmp = (int*)realloc(ps->a, sizeof(int) * newcapacity);
		if (tmp == NULL)
		{
			printf("error");
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = data;
	ps->top++;
}
//����
void stackDestroy(stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->capacity = ps->top = 0;
}
//ɾ��һ��Ԫ��
void stackPop(stack* ps)
{
	assert(ps);
	assert(!stackempty);
	ps->a[ps->top] = 0;
	ps->top--;
}
//ȡջ��������
int stackTop(stack* ps)
{
	assert(ps);
	assert(!stackempty(ps));//ջ�в���Ϊ��
	return ps->a[ps->top - 1];
}
//�ж�ջ���Ƿ�Ϊ��
bool stackempty(stack* ps)
{
	assert(ps);
	return ps->top == 0;
}