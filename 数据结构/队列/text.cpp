#include "head.h"
#include "QueueFun.cpp"
using namespace std;

ElemType e;

int main(){
	LinkQueue Q;
	InitQueue(Q);
	InsertInit(Q);
	printf("����Ԫ��\n");
	QueueTraverse(Q);
	printf("��ͷԪ�أ�");
	GetHead(Q,e);
	printf("%d\n",e);
	printf("���г��ȣ�");
	printf("%d\n",QueueLength(Q)); 
	return 0;
} 
