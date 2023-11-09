#include "head.h"
#include "QueueFun.cpp"
typedef int ElemType;

typedef struct StackNode {
	ElemType data;
	StackNode *next;
} StackNode, *StackPtr;

typedef struct {
	StackPtr head;//ջ��
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

//1.����һ����ջ
Status InitStack(LinkStack &s, int length) {
	s.head = NULL;
	s.length = length;
	return OK;
}

//6.����Ԫ��
Status Push(StackPtr &s, ElemType &data) {
	StackPtr p = new StackNode();
	p->data = data;
	p->next = s;
	s = p;
	return OK;
}

//4.�ж��Ƿ�Ϊ��
Status StackEmpty(StackPtr &s) {
	return s == NULL;
}

//5.����ջ��Ԫ��
Status GetTop(StackPtr &s, ElemType &data) {
	if (StackEmpty(s))
		return ERROR;
	data = s->data;
	return OK;
}

//7.����Ԫ��
Status Pop(StackPtr &s, ElemType &data) {
	if (StackEmpty(s))
		return ERROR;
	data = s->data;
	StackNode *p = s;
	s = s->next;
	delete p;
	return OK;
}

//�����ض���Ԫ��
//ͣ����  ����ջ  ���  ɾ���ĳ���
Status PopNumber(StackPtr &s, StackPtr &d, LinkQueue side, ElemType &value) {
	//���븨��ջ
	while (s->data != value) {
		Push(d, s->data);
		s = s->next;
	}
	//�����ض���Ԫ��
	Pop(s, value);
	while (d) {
		Push(s, d->data);
	}
	//��������Ϊ��
	if (!QueueEmpty(side)) {
		ElemType data;
		DeQueue(side, data);
		Push(s, data);
	}
	return OK;
}

//2.ջ������
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

//3.��Ϊ��ջ
Status ClearStack(StackPtr &s) {
	StackNode *p = new StackNode();
	while (s != NULL) {
		p = s;
		s = s->next;
		delete p;
	}
	return OK;
}

//9.�������
Status StackTraverse(StackPtr s) {
	while (s != NULL) {
		printf("%d ", s->data);
		s = s->next;
	}
	cout << endl;
	return OK;
}
