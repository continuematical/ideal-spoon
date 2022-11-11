#pragma once
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct QueneNode {
	int data;
	QueneNode* next;
};

struct Quene {
	QueneNode* head;
	QueneNode* tail;
};

//�ö���ʵ��ջ
typedef struct {
	Quene* q1;
	Quene* q2;
}MyStack;

void QueneInit(Quene* ps);
void QueneNodeDestroy(Quene* ps);
void QuenePush(Quene* ps, int data);
void QuenePop(Quene* ps);
bool QueneEmpty(Quene* ps);
int QueneFront(Quene* ps);
int QueneBack(Quene* ps);
int QueneSize(Quene* ps);

//�ö���ʵ��ջ�ĺ���
MyStack* MyStackCreat();
MyStack* MystackPush(MyStack* stack, int data);
int MyStackPop(MyStack* stack);
int MyStackTop(MyStack* stack);
bool MyStackEmpty(MyStack* stack);
void MyStackDestroy(MyStack* stack);