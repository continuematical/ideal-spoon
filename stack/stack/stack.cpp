#include "stack.h"
//初始化
void stackInit(stack* ps)
{
	assert(ps != NULL);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}
//插入一个元素
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
//销毁
void stackDestroy(stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->capacity = ps->top = 0;
}
//删除一个元素
void stackPop(stack* ps)
{
	assert(ps);
	assert(!stackempty);
	ps->a[ps->top] = 0;
	ps->top--;
}
//取栈顶的数据
int stackTop(stack* ps)
{
	assert(ps);
	assert(!stackempty(ps));//栈中不能为空
	return ps->a[ps->top - 1];
}
//判断栈中是否为空
bool stackempty(stack* ps)
{
	assert(ps);
	return ps->top == 0;
}