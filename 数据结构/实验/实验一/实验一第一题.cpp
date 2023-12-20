#include<bits/stdc++.h>
using namespace std;

// 链表节点的结构体
typedef struct Node {
    int data;
    Node* next;
}Node, *LinkList;

// 在链表尾部添加新节点
void append(LinkList& head, int value) {
    Node* newNode = (Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void init(LinkList& L1, LinkList& L2, LinkList& L3){
	for(int i=0;i<4;i++)	append(L1, i);
	for(int i=4;i<8;i++)	append(L2, i);
	for(int i=8;i<12;i++)	append(L3, i);
	
	
	LinkList& lastNode1 = L1;
	while (lastNode1->next != NULL) 	lastNode1 = lastNode1->next;
	
	LinkList& lastNode2 = L2;
	while (lastNode2->next != NULL) 	lastNode2 = lastNode2->next;
	
	lastNode1->next=L3;
	lastNode2->next=L3;
} 

LinkList find(LinkList L1, LinkList L2){
	LinkList head1=L1;LinkList head2=L2;
	while(head1->next != NULL){
		while(head2->next != NULL){
			if(head1 == head2)	return head1;
			head2=head2->next;
		}
		head1=head1->next;
		head2=L2;
	}
	return NULL;
}

int main(){
	LinkList L1=NULL, L2=NULL, L3=NULL;
	init(L1, L2, L3);
	cout<<find(L1, L2)->data<<endl;
	return 0;
}
