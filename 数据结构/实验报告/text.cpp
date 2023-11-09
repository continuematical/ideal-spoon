#include <bits/stdc++.h>
#include "LinkStackFun.cpp"

using namespace std;
int number, n;
char flag;
LinkStack garage, aval;
LinkQueue sideway;

void init() {
	printf("Input the garage capacity\n");
	scanf("%d", &n);
	InitStack(garage, n);
	InitStack(aval, n);
	printf("Input the sideway capacity\n");
	scanf("%d", &n);
	InitQueue(sideway, n);
}

int main() {
	init();
	StackPtr GHead = garage.head;
	StackPtr AHead = aval.head;
	do {
		printf("������ָ��ͳ��ƺţ�\n"); 
		cin >> flag >> number;
		if (toupper(flag) == 'A') {
			if (StackLength(GHead) < garage.length) {
				printf("�����복��\n"); 
				Push(GHead, number);
				printf("Garage status:");
				StackTraverse(GHead);
			} else {
				printf("����������������\n");
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
			printf("Input error");
		}
	} while (number > 0);
	return 0;
}
