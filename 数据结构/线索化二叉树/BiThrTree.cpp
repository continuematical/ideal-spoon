#include<bits/stdc++.h>
using namespace std;

#define TElemType char
#define Status int
#define OK 1
#define ERROR 0 

//������������ 
enum PointerTag{
	Link, //ָ�� 
	Thread,//���� 
};

typedef struct BiThrNode{
	TElemType data;
	BiThrNode* lchild, *rchild;
	PointerTag ltag, rtag;
}BiThrNode, *BiThrTree; 

//���ʽڵ�
Status visit(TElemType e){
	cout<<e<<endl;
	return OK; 
} 

BiThrTree pre;//ȫ�ֱ��� 

//������������
Status createBiThrTree(BiThrTree& T){
	TElemType ch;cin>>ch;
	if (ch == ' ') 	T = NULL;
	else{
		T=(BiThrTree)malloc(sizeof(BiThrTree));
		if(!T)	return(_OVERFLOW);
		T->data=ch;
		createBiThrTree(T->lchild);
		createBiThrTree(T->rchild); 
	}
	return OK;
} 

//��pΪ�ڵ������������ʼ�� 
void InThreading(BiThrTree p){
	if(p){
		InThreading(p->lchild);
		if(!p->lchild){
			p->ltag=Thread;
			p->lchild=pre;
		}else	p->ltag=Link; 
		
		if(!pre->rchild){
			pre->rtag=Thread;
			pre->rchild=p;
		}else	pre->rtag=Link;
		pre=p;
		InThreading(p->rchild); 
	}
}

//��ͷ��������������
Status InOrderThreading(BiThrTree& head, BiThrTree& T){
	//headΪͷ���
	if(!(head=(BiThrTree)malloc(sizeof(BiThrTree))))	exit(_OVERFLOW);
	head->ltag=Link;
	head->rtag=Thread;
	head->rchild=head;//��ʼʱ���ҽڵ�ָ���Լ�
	//�����Ϊ�գ���ڵ�Ҳָ���Լ� 
	if(!T)	head->lchild=head;
	else{
		head->lchild=T;pre=head;
		InThreading(T);
	} 
}

//TΪͷ��� 
Status InOrderTraverse_Thr(BiThrTree& T, Status(*visit) (TElemType e)){
	BiThrTree p=T->lchild;
	while(p!=T){
		while(p->ltag==Link)	p=p->lchild;
		cout<<p->data<<" ";
		while(p->rtag==Thread && p->rchild!=T){
			p=p->rchild;
			cout<<p->data<<" ";
		}
		p=p->rchild;
	}
	return OK;
}

int main(){
	pre->rtag = Thread;
	pre->rchild = NULL;
	BiThrTree tree, head;
	//��������
	//ABCD E   F  GHI   J K
	cout << "�����뽨��������������У�\n";
	createBiThrTree(tree);                 //����
	InOrderThreading(head, tree);       //������
	cout << "������������������Ľ��Ϊ��\n";
	InOrderTraverse_Thr(head, visit);    //�����������������
	cout << endl;
 
	system("pause");
	return 0;
}
