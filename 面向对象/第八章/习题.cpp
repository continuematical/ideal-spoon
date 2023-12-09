#include<bits/stdc++.h>
using namespace std;

//3.Student 类模板 
template<class TNO, class TScore, int num>
class Student{
	private:
		int n;
		TNO StudentID[num];
		TScore score[num];
		
	public:
		void append(TNO ID, TScore s);
		void Delete(TNO ID);
		int search(TNO ID);
		void sort();
		void DispAll();
		void DelList();
		Student(){
			n=0;
		}
}; 

template<class TNO, class TScore, int num>
void Student<TNO, TScore, num>::append(TNO ID, TScore s){
	if(n<num){
		StudentID[n]=ID;
		score[n]=s;
		n++;
	}
} 

template<class TNO, class TScore, int num>
void Student<TNO, TScore, num>::Delete(TNO ID){
	for(int i=0;i<n;i++){
		if(StudentID[i]==ID){
			for(int j=i;j<n;j++){
				StudentID[j]=StudentID[j+1];
				score[j]=score[j+1];
			}
			n--;
		}
	}
} 

template<class TNO, class TScore, int num>
int Student<TNO, TScore, num>::search(TNO ID){
	for(int i=0;i<n;i++)
		if(StudentID[i]==ID)	return i+1;
	return 0;
}

template<class TNO, class TScore, int num>
void Student<TNO, TScore, num>::sort(){
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(score[i]<score[j]){
				TScore ts;
				TNO tn;
				ts=score[i], tn=StudentID[i];
				score[i]=score[j], StudentID[i]=StudentID[j];
				score[j]=ts, StudentID[j]=tn;
			}
}

template<class TNO, class TScore, int num>
void Student<TNO, TScore, num>::DispAll(){
	for(int i=0;i<n;i++)
		cout<<StudentID[i]<<'\t'<<score[i]<<endl;
}


//4.单向链表模板
template<class TYPE>

class ListNode{
	private:
		TYPE data;
		ListNode* next;
		static ListNode* curNode;
		static ListNode* head;
	public:
		ListNode():next(NULL){
			head=curNode=this;
		}
		
		ListNode(TYPE newData):data(newData), next(NULL){
			
		}
		
		void InsertNode(TYPE node);
		void DeleteNode(TYPE node);
		void DispList();
		void DelList();
}; 

template<class TYPE>
void ListNode<TYPE>::InsertNode(TYPE newData){
	ListNode* preNode,*tempNode;
	preNode=head;
	curNode=preNode->next;
	while(curNode!=NULL && curNode->data<newData){
		preNode=curNode;
		curNode=curNode->next;
	}
	if(curNode==NULL)
		preNode->next=new ListNode(newData);
	else{
		tempNode=new ListNode(newData);
		tempNode->next=curNode;
		preNode->next=tempNode;
	}
}

template<class TYPE>
void ListNode<TYPE>::DeleteNode(TYPE newData){
	ListNode* preNode;
	preNode=head;
	curNode=preNode->next;
	while(curNode!=NULL && curNode->data<newData){
		preNode=curNode;
		curNode=curNode->next;
	}
	while(curNode!=NULL && curNode->data==newData){
		preNode->next=curNode->next;
		delete curNode;
		curNode=preNode->next; 
	}
}

template<class TYPE>
void ListNode<TYPE>::DispList(){
	curNode=head->next;
	while(curNode!=NULL){
		cout<<curNode->data<<endl;
		curNode=curNode->next;
	}
} 

template<class TYPE>
void ListNode<TYPE>::DelList(){
	ListNode* q;
	curNode=head->next;
	while(curNode!=NULL){
		q=curNode->next;
		delete curNode;
		curNode=q;
	}
	head->next=NULL;
}
