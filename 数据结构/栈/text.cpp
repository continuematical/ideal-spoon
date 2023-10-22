#include "head.h"
#include "LinkStackFun.cpp"

using namespace std;
int data;

int main(){
	LinkStack p=newNode();
	InitStack(p);
	Input(p);
	StackTraverse(p);
	int length=StackLength(p);
	
	printf("ջ�ĳ���Ϊ��\n"); 
	printf("%d\n", length);
	
	printf("������ջԪ��\n");
	scanf("%d",&data);
	Push(p,data);
	StackTraverse(p); 
	
	printf("��ȡջ��Ԫ��\n");
	if(GetTop(p,data))	printf("%d\n", data);
	else	printf("ջΪ��ջ\n");
	
	printf("��ջ\n");
	if(Pop(p,data))	printf("%d\n",data);
	else	printf("ջΪ��ջ\n");
	StackTraverse(p);
	return 0; 
} 
