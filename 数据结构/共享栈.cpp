#include<bits/stdc++.h> 
#define SharedStackMax 100

typedef char SharedStackType;
typedef struct SharedStack{
	SharedStackType data[SharedStackMax];
	int top1;
	int top2;
}SharedStack; 

//³õÊ¼»¯ 
void SharedStackInit(SharedStack* stack){
	if(stack==NULL)	return;
	stack->top1=0;
	stack->top2=SharedStackMax;
}

//ÅÐ¶ÏÕ»Âú
bool isSharedStackFull(SharedStack* stack){
	return stack->top1 + 1 == stack->top2;
} 

//ÅÐ¶ÏÕ»1¿Õ
bool isSharedStackEmpty1(SharedStack* stack){
	return stack->top1==0;
} 

//ÅÐ¶ÏÕ»2¿Õ
bool isSharedStackEmpty2(SharedStack* stack){
	return stack->top1==SharedStackMax;
}  

//push Õ»1
void SharedStackPush1(SharedStack* stack, SharedStackType value){
	if(stack==NULL)	return;
	if(isSharedStackFull(stack))	return;
	stack->data[++stack->top1]=value;
} 

//push Õ»2
void  SharedStackPush2(SharedStack* stack, SharedStackType value){
	if(stack==NULL)	return;
	if(isSharedStackFull(stack))	return;
	stack->data[--stack->top2]=value; 
}

//pop Õ»1
void SharedStackPop1(SharedStack* stack, SharedStackType &value){
	if(stack==NULL)	return;
	if(isSharedStackEmpty1(stack))	return;
	value=stack->data[stack->top1--];
	return;
} 

//pop Õ»2 
void SharedStackPop2(SharedStack* stack, SharedStackType &value){
	if(stack==NULL)	return;
	if(isSharedStackEmpty2(stack))	return;
	value=stack->data[stack->top2++];
	return;
} 

//top Õ»1 
void SharedStackTop1(SharedStack* stack, SharedStackType &value){
	if(stack==NULL)	return;
	if(isSharedStackEmpty1(stack))	return;
	value=stack->data[stack->top1];
	return;
}

//top Õ»2 
void SharedStackTop2(SharedStack* stack, SharedStackType &value){
	if(stack==NULL)	return;
	if(isSharedStackEmpty2(stack))	return;
	value=stack->data[stack->top2];
} 
