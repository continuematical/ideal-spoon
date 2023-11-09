#include "head.h"
#include "QueueFun.cpp"
typedef int ElemType;

typedef struct StackNode {
	ElemType data;
	StackNode *next;
} StackNode, *StackPtr;

typedef struct {
	StackPtr head;//栈顶
	int length;
} LinkStack;

int StackLength(StackPtr s) {
	int length = 0;
	while (s) {
		length++;
		s = s->next;
	}
	return length;
}

//1.构造一个空栈
Status InitStack(LinkStack &s, int length) {
	s.head = NULL;
	s.length = length;
	return OK;
}

//6.插入元素
Status Push(StackPtr &s, ElemType &data) {
	StackPtr p = new StackNode();
	p->data = data;
	p->next = s;
	s = p;
	return OK;
}

//4.判断是否为空
Status StackEmpty(StackPtr &s) {
	return s == NULL;
}

//5.返回栈顶元素
Status GetTop(StackPtr &s, ElemType &data) {
	if (StackEmpty(s))
		return ERROR;
	data = s->data;
	return OK;
}

//7.弹出元素
Status Pop(StackPtr &s, ElemType &data) {
	if (StackEmpty(s))
		return ERROR;
	data = s->data;
	StackNode *p = s;
	s = s->next;
	delete p;
	return OK;
}

//弹出特定的元素
//停车场  辅助栈  便道  删除的车号
Status PopNumber(StackPtr &s, StackPtr &d, LinkQueue side, ElemType &value) {
	//进入辅助栈
	while (s->data != value) {
		Push(d, s->data);
		s = s->next;
	}
	//弹出特定的元素
	Pop(s, value);
	while (d) {
		Push(s, d->data);
	}
	//如果便道不为空
	if (!QueueEmpty(side)) {
		ElemType data;
		DeQueue(side, data);
		Push(s, data);
	}
	return OK;
}

//2.栈被销毁
Status DestroyStack(StackPtr &s) {
	StackNode *p = new StackNode();
	while (s->next) {
		p = s;
		s = s->next;
		delete p;
	}
	p->next = NULL;
	return OK;
}

//3.清为空栈
Status ClearStack(StackPtr &s) {
	StackNode *p = new StackNode();
	while (s != NULL) {
		p = s;
		s = s->next;
		delete p;
	}
	return OK;
}

//9.依次输出
Status StackTraverse(StackPtr s) {
	while (s != NULL) {
		printf("%d ", s->data);
		s = s->next;
	}
	cout << endl;
	return OK;
}
