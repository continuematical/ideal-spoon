#include "head.h"

typedef struct LNode{
	ElemType data;
	LNode* next;
}LNode, *QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;


//1.��ʼ������
void InitQueue(LinkQueue& Q){
	Q.front=Q.rear=new LNode();
	Q.front->next=NULL;
} 

//2.���ٶ���
void DestroyQueue(LinkQueue& Q){
	while(Q.front){
		Q.rear=Q.front->next;
		delete Q.front;
		Q.front=Q.rear;
	}
} 

//3.��ն���
void ClearQueue(LinkQueue& Q){
	
} 

//4.�����Ƿ�Ϊ��
Status QueueEmpty(LinkQueue Q){
	return Q.front==Q.rear;
} 

//5.���г���
int QueueLength(LinkQueue Q){
	LNode* p=Q.front;
	int length=0;
	while(p<Q.rear){
		length++;
		p=p->next;
	}
	return length;
} 

//6.���ض�ͷԪ��
void GetHead(LinkQueue& Q, ElemType& e) {
	if(QueueEmpty(Q)){
		printf("�޶�ͷԪ��\n");
		return;
	}
	e=Q.front->next->data;
}

//7.����Ԫ��
void EnQueue(LinkQueue& Q, ElemType& e){
	LNode* p=new LNode();
	p->data=e;p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
} 

//8.ɾ����ͷԪ��
Status DeQueue(LinkQueue& Q, ElemType& e){
	if(QueueEmpty(Q))	return ERROR;
	LNode* p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)	Q.rear=Q.front;
	delete p;
	return OK;
} 

//9.��������Ԫ��
void QueueTraverse(LinkQueue Q){
	LNode* start=Q.front;
	while(start!=Q.rear){
		start=start->next;
		printf("%d ", start->data);
	}
	cout<<endl;
} 

//���� 
void InsertInit(LinkQueue& Q){
	int n;
	printf("�������Ԫ�صĸ�����\n");
	scanf("%d", &n);
	while(n--){
		int a;cin>>a;
		EnQueue(Q, a);
	}
}
