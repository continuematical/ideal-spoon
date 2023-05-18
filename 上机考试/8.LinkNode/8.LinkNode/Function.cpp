#include "��ͷ.h"

//�½��ڵ�
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

//��˳�����
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

//��ӡ����
void printList(Student* head) {
	Student* temp = head;
	while (temp != NULL) {
		printf("%s %f \n", temp->Name, temp->Total);
		temp = temp->next;
	}
}