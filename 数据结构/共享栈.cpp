#include<bits/stdc++.h> 
#define SharedStackMax 100

typedef char SharedStackType;
typedef struct SharedStack{
	SharedStackType data[SharedStackMax];
	int top1;
	int top2;
}SharedStack; 

//��ʼ�� 
void SharedStackInit(SharedStack* stack){
	if(stack==NULL)	return;
	stack->top1=0;
	stack->top2=SharedStackMax;
}

//�ж�ջ��
bool isSharedStackFull(SharedStack* stack){
	return stack->top1 + 1 == stack->top2;
} 

//�ж�ջ1��
bool isSharedStackEmpty1(SharedStack* stack){
	return stack->top1==0;
} 

//�ж�ջ2��
bool isSharedStackEmpty2(SharedStack* stack){
	return stack->top1==SharedStackMax;
}  

//push ջ1
void SharedStackPush1(SharedStack* stack, SharedStackType value){
	if(stack==NULL)	return;
	if(isSharedStackFull(stack))	return;
	stack->data[++stack->top1]=value;
} 

//push ջ2
void  SharedStackPush2(SharedStack* stack, SharedStackType value){
	if(stack==NULL)	return;
	if(isSharedStackFull(stack))	return;
	stack->data[--stack->top2]=value; 
}

//pop ջ1
void SharedStackPop1(SharedStack* stack, SharedStackType &value){
	if(stack==NULL)	return;
	if(isSharedStackEmpty1(stack))	return;
	value=stack->data[stack->top1--];
	return;
} 

//pop ջ2 
void SharedStackPop2(SharedStack* stack, SharedStackType &value){
	if(stack==NULL)	return;
	if(isSharedStackEmpty2(stack))	return;
	value=stack->data[stack->top2++];
	return;
} 

//top ջ1 
void SharedStackTop1(SharedStack* stack, SharedStackType &value){
	if(stack==NULL)	return;
	if(isSharedStackEmpty1(stack))	return;
	value=stack->data[stack->top1];
	return;
}

//top ջ2 
void SharedStackTop2(SharedStack* stack, SharedStackType &value){
	if(stack==NULL)	return;
	if(isSharedStackEmpty2(stack))	return;
	value=stack->data[stack->top2];
} 
