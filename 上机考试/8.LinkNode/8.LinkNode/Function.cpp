#include "标头.h"

//新建节点
Student* newNode(char Name[], double Maths, double English, double C) {
	Student* node = (Student*)malloc(sizeof(Student));
	node->Maths = Maths;
	node->English = English;
	node->C = C;
	node->Name = Name;
	node->Total = Maths + English + C;
	node->next = NULL;
	return node;
}

//按顺序插入
void insertNode(Student** head, char Name[], double Maths, double English, double C) {
	double total = Maths + English + C;
	Student* cur;
	while ((cur = *head) != NULL && cur->Total < total){
		head = &cur->next;
	}
	Student* node = newNode(Name, Maths, English, C);
	node->next = cur;
	*head = node;
}

//打印链表
void printList(Student* head) {
	Student* temp = head;
	while (temp != NULL) {
		printf("%s %f \n", temp->Name, temp->Total);
		temp = temp->next;
	}
}