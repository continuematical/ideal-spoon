#include "head.h"
#include "QueueFun.cpp"
using namespace std;

ElemType e;

int main(){
	LinkQueue Q;
	InitQueue(Q);
	InsertInit(Q);
	printf("遍历元素\n");
	QueueTraverse(Q);
	printf("队头元素：");
	GetHead(Q,e);
	printf("%d\n",e);
	printf("队列长度：");
	printf("%d\n",QueueLength(Q)); 
	return 0;
} 
