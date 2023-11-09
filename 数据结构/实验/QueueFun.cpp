#include "head.h"

typedef struct QueueNode {
	ElemType data;
	QueueNode *next;
} QueueNode, *QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
	int length;
} LinkQueue;


//1.初始化队列
void InitQueue(LinkQueue &Q, int number) {
	Q.front = Q.rear = new QueueNode();
	Q.front->next = NULL;
	Q.length = number;
}

//2.销毁队列
void DestroyQueue(LinkQueue &Q) {
	while (Q.front) {
		Q.rear = Q.front->next;
		delete Q.front;
		Q.front = Q.rear;
	}
}

//3.清空队列
void ClearQueue(LinkQueue &Q) {
	QueueNode *p = Q.front->next;
	QueueNode *q;
	while (p != Q.rear) {
		q = p;
		p = p->next;
		delete q;
	}
}

//4.队列是否为空
Status QueueEmpty(LinkQueue Q) {
	return Q.front == Q.rear;
}

//5.队列长度
int QueueLength(LinkQueue Q) {
	QueueNode *p = Q.front;
	int length = 0;
	while (p < Q.rear) {
		length++;
		p = p->next;
	}
	return length;
}

//6.返回队头元素
void GetHead(LinkQueue &Q, ElemType &e) {
	if (QueueEmpty(Q)) {
		printf("无队头元素\n");
		return;
	}
	e = Q.front->next->data;
}

//7.插入元素
void EnQueue(LinkQueue &Q, ElemType &e) {
	QueueNode *p = new QueueNode();
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}

//8.删除队头元素
Status DeQueue(LinkQueue &Q, ElemType &e) {
	if (QueueEmpty(Q))
		return ERROR;
	QueueNode *p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	delete p;
	return OK;
}

//9.遍历队列元素
void QueueTraverse(LinkQueue Q) {
	QueueNode *start = Q.front;
	while (start != Q.rear) {
		start = start->next;
		printf("%d ", start->data);
	}
	cout << endl;
}

//输入
void InsertInit(LinkQueue &Q) {
	int n;
	printf("输入插入元素的个数：\n");
	scanf("%d", &n);
	while (n--) {
		int a;
		cin >> a;
		EnQueue(Q, a);
	}
}
