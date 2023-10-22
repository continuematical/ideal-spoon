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

//5.返回链表长度 
int ListLength(LinkList L){
	LNode* p=L;
	int k=0;
	while(p){
		p=p->next;
		k++;
	}
	return k;
}

//6.获取指定元素
Status GetElem(LinkList L, int i, ElemType e){
	LNode* p=L;int j=1;
	//p指向头节点，j为计数
	while(j<=i && p){
		p=p->next;++j;
	} 
	if(!p || j>i)	return ERROR;//不存在第 i 个节点
	e=p->data;
	return OK; 
} 

//7.返回数据元素的位置 
int LocateElem(LinkList L, ElemType e){
	LNode* p=L;int k=0;//编号 
	while(p->next){
		p=p->next;k++;
		if(p->data==e)	return k;
	}
	return ERROR;
}

//8.返回前驱
Status PriorElem(LinkList& L, ElemType cur_e, ElemType& pre_e){
	LinkList p=L->next;//指向第一个元素 
	LNode* s=L;//保存前驱 
	while(p){
		if(p->data==cur_e){
			if(s==L)	return ERROR; 
			pre_e=s->data; 
			return OK;
		}
		s=p;p=p->next;
	}
}

//9.返回后继
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
 
//10.在链表的第 i 个位置插入元素 
Status ListInsert(LinkList& L, int i, ElemType& e){
	LNode* p=L;int j=0;
	while(p && j<i-1){
		p=p->next;
		j++;
	}
	//p指向第i-1个位置的节点 
	if(!p || j>i-1)	return ERROR;
	//生成新结点
	LNode* node=newNode();
	node->data=e;node->next=p->next;
	p->next=node;
	return OK;
}

//11.删除第 i 个元素 
Status ListDelete(LinkList& L, int i, ElemType& e){
	LNode* p=L;int j=0;
	while(p&&j<i-1){
		p=p->next;
		j++;
	}
	//p指向第i-1个位置的节点
	if(!p||j>i-1)	return ERROR;
	//q指向第i个节点 
	LNode* q=p->next; 
	e=q->data;
	p->next=q->next;
	free(q); 
	return OK;
} 

//1.初始化链表 
Status InitList(LinkList& L, int n){
	LinkList p=L;
	for(int i=0;i<n;i++){
		LNode* node=newNode();
		scanf("%d",&(node->data));
		p->next=node;
		p=node; 
	}
}

//2.销毁链表 
Status DestroyList(LinkList& L){
	LNode* p=L,*s=L;
	while(p){
		s=p;p=p->next; 
		free(s);
	}
	return OK;
} 

//3.将链表重置为空表
Status clearList(LinkList& L){
	LNode* p=L->next,*s;
	while(p){
		s=p;p=p->next; 
		free(s);
	}
	L->next=NULL; 
	return OK;
} 

//4.判断链表是否为空表
int ListEmpty(LinkList L){
	if(L->next)	return false;
	else	return true;
} 

//12.遍历链表
//头结点 
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
