#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Stack {
    char data[MAX_SIZE];
    int top;
}Stack;

// ��ʼ��ջ
void initialize(Stack* stack) {
    stack->top = -1;
}

// �ж�ջ�Ƿ�Ϊ��
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// ��ջ����
void push(Stack* stack, char value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("ջ�������޷���ջ\n");
        exit(EXIT_FAILURE);
    }

    stack->data[++stack->top] = value;
}

// ��ջ����
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("ջΪ�գ��޷���ջ\n");
        exit(EXIT_FAILURE);
    }

    return stack->data[stack->top--];
}

// �жϸ�������ջ�ͳ�ջ�ַ������Ƿ����������������ջ�Ĺ���
int isStackSequenceValid(char* pushSequence, char* popSequence, int length) {
    Stack stack;
    initialize(&stack);

    int pushIndex = 0, popIndex = 0;

    while (popIndex < length) {
        // ���ջΪ�ջ���ջ��Ԫ�ز����ڵ�ǰ��ջԪ�أ�����ջ
        while (isEmpty(&stack) || stack.data[stack.top] != popSequence[popIndex]) {
            if (pushIndex == length) 
                return 0;  // ��ջ�����ѱ����꣬�����г�ջԪ��δƥ��

            printf("%c��\n", pushSequence[pushIndex]);
            push(&stack, pushSequence[pushIndex++]);
        }

        // ջ��Ԫ�ص��ڵ�ǰ��ջԪ�أ���ջ 
        printf("%c��\n", popSequence[popIndex]);
        pop(&stack);
        popIndex++;
    }

    return 1;  // ����ջ˳�����
}

int main() {
    char pushSequence1[] = {'1', '2', '3'};
    char popSequence1[] = {'2', '1', '3'};

    printf("��1��\n");
    if (isStackSequenceValid(pushSequence1, popSequence1, 3)) {
        printf("����ջ˳�����\n");
    } else {
        printf("����ջ˳�򲻳���\n");
    }

    char pushSequence2[] = {'1', '2', '3', '4'};
    char popSequence2[] = {'4', '2', '3', '1'};

    printf("\n��2��\n");
    if (isStackSequenceValid(pushSequence2, popSequence2, 4)) 	printf("����ջ˳�����\n");
    else 	printf("����ջ˳�򲻳���\n");

    return 0;
}
