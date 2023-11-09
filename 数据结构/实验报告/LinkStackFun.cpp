#include "head.h"
#include "QueueFun.cpp"

typedef struct StackNode {
	ElemType data;
	StackNode *next;
} StackNode, *StackPtr;

typedef struct {
	StackPtr head;//
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

//1.
Status InitStack(LinkStack &s, int length) {
	s.head = NULL;
	s.length = length;
	return OK;
}

//6.
Status Push(StackPtr &s, ElemType &data) {
	//
	StackPtr p = new StackNode();
	p->data = data;
	p->next = s;
	s = p;
	return OK;
}

//输入栈顶指针，判断栈是否为空
Status StackEmpty(StackPtr &s) {
	return s == NULL;
}

//5.输入栈顶指针，取出栈顶元素放在data里
Status GetTop(StackPtr &s, ElemType &data) {
	if (StackEmpty(s))
		return ERROR;
	data = s->data;
	return OK;
}

//出栈
Status Pop(StackPtr &s, ElemType &data) {
	if (StackEmpty(s))
		return ERROR;
	data = s->data;
	StackNode *p = s;
	s = s->next;
	delete p;
	return OK;
}

//停车场	辅助栈	便道	要离开停车场的车号
Status PopNumber(StackPtr &s, StackPtr &d, LinkQueue side, ElemType &value) {
	ElemType data;
	//让外边的车进入辅助栈
	while (s->data != value) {
		Pop(s,data);
		Push(d, data);
	}
	printf("enter\n");
	//指定车离开停车场
	Pop(s, value);
	while (d) {
		Pop(d,data);
		Push(s, data);
	}
	printf("exit\n");
	//如果便道有车，则便道的车进入停车场
	if (!QueueEmpty(side)) {
		DeQueue(side, data);
		Push(s, data);
	}
	printf("sideway\n");
	return OK;
}

//2.销毁栈
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

//3.清空栈
Status ClearStack(StackPtr &s) {
	StackNode *p = new StackNode();
	while (s != NULL) {
		p = s;
		s = s->next;
		delete p;
	}
	return OK;
}

//9.列举每一个元素
Status StackTraverse(StackPtr s) {
	while (s != NULL) {
		printf("%d ", s->data);
		s = s->next;
	}
	printf("|");
	cout << endl;
	return OK;
}
