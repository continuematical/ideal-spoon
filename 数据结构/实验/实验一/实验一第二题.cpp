#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
	int data;
	Node* next;
}Node, *LinkList;

void append(LinkList& head, int value){
	Node* node=new Node;
	node->data=value;
	node->next=NULL;
	
	if(head==NULL){
		head=node;
		return;
	}
	
	Node* cur=head;
	while(cur->next!=NULL)	cur=cur->next;
	
	cur->next=node; 
} 

void Link(LinkList& L1, LinkList& L2){
	Node* head=L1;
	while(head->next != NULL)	head=head->next;
	head->next=L2;
}

void Init(LinkList& L){
	for(int i=0;i<10;i++)	append(L, i);
}

void change(LinkList& L, LinkList& L1, LinkList& L2){
	Node* p=L;
	int flag=0;
	while(p){
		int value=p->data;
		if(flag%2)	append(L1, value);
		else	append(L2, value);
		p=p->next; 
		flag++;
	}
}

void traverse(LinkList& L){
	Node* head=L;
	while(head){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
} 

int main(){
	LinkList L=NULL, L1=NULL, L2=NULL;
	printf("初始化："); 
	Init(L); 
	traverse(L);
	printf("调整后：");
	change(L, L1, L2);
	Link(L1, L2);
	traverse(L1);
	return 0;
} 
