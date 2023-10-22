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
	
	printf("栈的长度为：\n"); 
	printf("%d\n", length);
	
	printf("输入入栈元素\n");
	scanf("%d",&data);
	Push(p,data);
	StackTraverse(p); 
	
	printf("获取栈顶元素\n");
	if(GetTop(p,data))	printf("%d\n", data);
	else	printf("栈为空栈\n");
	
	printf("出栈\n");
	if(Pop(p,data))	printf("%d\n",data);
	else	printf("栈为空栈\n");
	StackTraverse(p);
	return 0; 
} 
