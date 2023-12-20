#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Stack {
    char data[MAX_SIZE];
    int top;
}Stack;

// 初始化栈
void initialize(Stack* stack) {
    stack->top = -1;
}

// 判断栈是否为空
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// 入栈操作
void push(Stack* stack, char value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("栈已满，无法入栈\n");
        exit(EXIT_FAILURE);
    }

    stack->data[++stack->top] = value;
}

// 出栈操作
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("栈为空，无法出栈\n");
        exit(EXIT_FAILURE);
    }

    return stack->data[stack->top--];
}

// 判断给定的入栈和出栈字符序列是否成立，并描述出入栈的过程
int isStackSequenceValid(char* pushSequence, char* popSequence, int length) {
    Stack stack;
    initialize(&stack);

    int pushIndex = 0, popIndex = 0;

    while (popIndex < length) {
        // 如果栈为空或者栈顶元素不等于当前出栈元素，则入栈
        while (isEmpty(&stack) || stack.data[stack.top] != popSequence[popIndex]) {
            if (pushIndex == length) 
                return 0;  // 入栈序列已遍历完，但仍有出栈元素未匹配

            printf("%c入\n", pushSequence[pushIndex]);
            push(&stack, pushSequence[pushIndex++]);
        }

        // 栈顶元素等于当前出栈元素，出栈 
        printf("%c出\n", popSequence[popIndex]);
        pop(&stack);
        popIndex++;
    }

    return 1;  // 出入栈顺序成立
}

int main() {
    char pushSequence1[] = {'1', '2', '3'};
    char popSequence1[] = {'2', '1', '3'};

    printf("例1：\n");
    if (isStackSequenceValid(pushSequence1, popSequence1, 3)) {
        printf("出入栈顺序成立\n");
    } else {
        printf("出入栈顺序不成立\n");
    }

    char pushSequence2[] = {'1', '2', '3', '4'};
    char popSequence2[] = {'4', '2', '3', '1'};

    printf("\n例2：\n");
    if (isStackSequenceValid(pushSequence2, popSequence2, 4)) 	printf("出入栈顺序成立\n");
    else 	printf("出入栈顺序不成立\n");

    return 0;
}
