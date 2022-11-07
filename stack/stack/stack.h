#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct stack {
	int* a;
	int top;
	int capacity;
};

void stackInit(stack* ps);
void stackPush(stack* ps, int data);
void stackPop(stack* ps);
void stackDestroy(stack* ps);
bool stackempty(stack* ps);
int stackTop(stack* ps);