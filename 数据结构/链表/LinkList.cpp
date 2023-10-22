#include "head.h"
typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;

LNode* newNode(){
	LNode* node = (LNode*)malloc(sizeof(LNode));
	node->next=NULL;
	return node;
} 

//5.���������� 
int ListLength(LinkList L){
	LNode* p=L;
	int k=0;
	while(p){
		p=p->next;
		k++;
	}
	return k;
}

//6.��ȡָ��Ԫ��
Status GetElem(LinkList L, int i, ElemType e){
	LNode* p=L;int j=1;
	//pָ��ͷ�ڵ㣬jΪ����
	while(j<=i && p){
		p=p->next;++j;
	} 
	if(!p || j>i)	return ERROR;//�����ڵ� i ���ڵ�
	e=p->data;
	return OK; 
} 

//7.��������Ԫ�ص�λ�� 
int LocateElem(LinkList L, ElemType e){
	LNode* p=L;int k=0;//��� 
	while(p->next){
		p=p->next;k++;
		if(p->data==e)	return k;
	}
	return ERROR;
}

//8.����ǰ��
Status PriorElem(LinkList& L, ElemType cur_e, ElemType& pre_e){
	LinkList p=L->next;//ָ���һ��Ԫ�� 
	LNode* s=L;//����ǰ�� 
	while(p){
		if(p->data==cur_e){
			if(s==L)	return ERROR; 
			pre_e=s->data; 
			return OK;
		}
		s=p;p=p->next;
	}
}

//9.���غ��
Status NextElem(LinkList& L, ElemType cur_e, ElemType& nex_e){
	LinkList p=L->next;
	while(p){
		if(p->data==cur_e){
			if(p->next){
				nex_e=p->next->data;
				return OK;
			}
			return ERROR;
		}
		p=p->next;
	}
} 
 
//10.������ĵ� i ��λ�ò���Ԫ�� 
Status ListInsert(LinkList& L, int i, ElemType& e){
	LNode* p=L;int j=0;
	while(p && j<i-1){
		p=p->next;
		j++;
	}
	//pָ���i-1��λ�õĽڵ� 
	if(!p || j>i-1)	return ERROR;
	//�����½��
	LNode* node=newNode();
	node->data=e;node->next=p->next;
	p->next=node;
	return OK;
}

//11.ɾ���� i ��Ԫ�� 
Status ListDelete(LinkList& L, int i, ElemType& e){
	LNode* p=L;int j=0;
	while(p&&j<i-1){
		p=p->next;
		j++;
	}
	//pָ���i-1��λ�õĽڵ�
	if(!p||j>i-1)	return ERROR;
	//qָ���i���ڵ� 
	LNode* q=p->next; 
	e=q->data;
	p->next=q->next;
	free(q); 
	return OK;
} 

//1.��ʼ������ 
Status InitList(LinkList& L, int n){
	LinkList p=L;
	for(int i=0;i<n;i++){
		LNode* node=newNode();
		scanf("%d",&(node->data));
		p->next=node;
		p=node; 
	}
}

//2.�������� 
Status DestroyList(LinkList& L){
	LNode* p=L,*s=L;
	while(p){
		s=p;p=p->next; 
		free(s);
	}
	return OK;
} 

//3.����������Ϊ�ձ�
Status clearList(LinkList& L){
	LNode* p=L->next,*s;
	while(p){
		s=p;p=p->next; 
		free(s);
	}
	L->next=NULL; 
	return OK;
} 

//4.�ж������Ƿ�Ϊ�ձ�
int ListEmpty(LinkList L){
	if(L->next)	return false;
	else	return true;
} 

//12.��������
//ͷ��� 
Status ListTraverse(LinkList L){
	LNode* p=L->next;
	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
	return OK;
} 

Status jiao(LinkList La, LinkList Lb, LinkList &Lc){
	int lengthB=ListLength(Lb);
	LNode* p=Lb->next;int k=1;
	for(int i=1;i<lengthB;i++){
		if(LocateElem(La, p->data))		ListInsert(Lc, k++, p->data);
		p=p->next;
	}
	return OK;
}

Status bing(LinkList La, LinkList Lb, LinkList &Lc){
	int lengthA=ListLength(La);
	int lengthB=ListLength(Lb);
	LNode* p=La->next;
	for(int i=1;i<lengthA;i++){
		ListInsert(Lc,i,p->data);
		p=p->next;
	}
	p=Lb->next;
	for(int i=1;i<lengthB;i++){
		if(!LocateElem(La, p->data))	ListInsert(Lc,lengthA,p->data);
		p=p->next;
	}
	return OK;
}

Status cha(LinkList La, LinkList Lb, LinkList& Lc){
	int lengthA=ListLength(La);
	LNode* p=La->next;int k=1;
	for(int i=1;i<lengthA;i++){
		if(!LocateElem(Lb, p->data))		ListInsert(Lc, k++, p->data);
		p=p->next;
	}
	return OK;
}
