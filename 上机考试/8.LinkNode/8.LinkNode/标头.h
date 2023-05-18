struct Student
{
	char* Name;
	double Maths;
	double English;
	double C;
	double Total;
	Student* next;
}; 

Student* newNode(char Name[], double Maths, double English, double C);
void insertNode(Student** head, char Name[], double Maths, double English, double C);
void printList(Student* head);

#include<malloc.h>
#include<stdio.h>