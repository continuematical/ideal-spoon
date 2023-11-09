#include <bits/stdc++.h>
#include "QueueFun.cpp"

using namespace std;
int number, n;
char flag;
LinkStack garage, aval;
LinkQueue sideway;

//初始化
void init() {
	printf("输入停车场容量：\n");
	scanf("%d", &n);
	InitStack(garage, n);
	InitStack(aval, n);
	printf("输入通道容量：\n");
	scanf("%d", &n);
	InitQueue(sideway, n);
}

int main() {
	init();
	StackPtr GHead = garage.head;
	StackPtr AHead = aval.head;
	do {
		cin >> flag >> number;
		if (toupper(flag) == 'A') {
			if (StackLength(GHead) < garage.length) {
				Push(GHead, number);
				printf("Garage status:");
				StackTraverse(GHead);
			} else {
				EnQueue(sideway, number);
				printf("Garage status:");
				StackTraverse(GHead);
				printf("sideway status:");
				QueueTraverse(sideway);
			}
		} else if (toupper(flag) == 'D') {
			PopNumber(GHead, AHead, sideway, number);
			printf("Garage status:");
			StackTraverse(GHead);
		} else {
			printf("输入错误\n");
		}
	} while (number > 0);
	return 0;
}
