#include "head.h"
typedef int ElemType;

typedef struct LNode {
	ElemType data;
	LNode *next;
} LNode, *LinkStack;

//1.����һ����ջ
Status InitStack(LinkStack &s) {
	s = NULL;
	return OK;
}

//6.����Ԫ��
Status Push(LinkStack &s, ElemType data) {
	LNode *p = new LNode();
	p->data = data;
	p->next = s;
	s = p;
	return OK;
}

void Input(LinkStack &s) {
	int num;
	printf("������Ԫ�ظ�����\n");
	scanf("%d", &num);
	while (num--) {
		ElemType data;
		scanf("%d", &data);
		Push(s, data);
	}
}

//4.�ж��Ƿ�Ϊ��
Status StackEmpty(LinkStack &s) {
	return s == NULL;
}

//5.����ջ��Ԫ��
Status GetTop(LinkStack &s, ElemType &data) {
	if (StackEmpty(s))
		return ERROR;
	data = s->data;
	return OK;
}

//7.����Ԫ��
Status Pop(LinkStack &s, ElemType &data) {
	if (StackEmpty(s))
		return ERROR;
	data = s->data;
	LNode *p = s;
	s = s->next;
	delete p;
	return OK;
}

//2.ջ������
Status DestroyStack(LinkStack &s) {
	LNode *p = new LNode();
	while (s->next) {
		p = s;
		s = s->next;
		delete p;
	}
	p->next = NULL;
	return OK;
}

//3.��Ϊ��ջ
Status ClearStack(LinkStack &s) {
	LNode *p = new LNode();
	while (s != NULL) {
		p = s;
		s = s->next;
		delete p;
	}
	return OK;
}

//9.�������
Status StackTraverse(LinkStack s) {
	LNode *p = new LNode();
	while (s->next != NULL) {
		printf("%d ", s->data);
		s = s->next;
	}
	cout << endl;
	delete p;
	return OK;
}

int StackLength(LinkStack s) {
	int length = -1;
	while (s != NULL) {
		length++;
		s = s->next;
	}
	return length;
}


