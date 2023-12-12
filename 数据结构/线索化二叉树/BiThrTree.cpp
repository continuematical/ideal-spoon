#include<bits/stdc++.h>
using namespace std;

#define TElemType char
#define Status int
#define OK 1
#define ERROR 0 

//线索化二叉树 
enum PointerTag{
	Link, //指针 
	Thread,//线索 
};

typedef struct BiThrNode{
	TElemType data;
	BiThrNode* lchild, *rchild;
	PointerTag ltag, rtag;
}BiThrNode, *BiThrTree; 

//访问节点
Status visit(TElemType e){
	cout<<e<<endl;
	return OK; 
} 

BiThrTree pre;//全局变量 

//建立二叉链表
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

//以p为节点的中序线索初始化 
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

//带头结点的中序线索化
Status InOrderThreading(BiThrTree& head, BiThrTree& T){
	//head为头结点
	if(!(head=(BiThrTree)malloc(sizeof(BiThrTree))))	exit(_OVERFLOW);
	head->ltag=Link;
	head->rtag=Thread;
	head->rchild=head;//初始时，右节点指向自己
	//如果树为空，左节点也指向自己 
	if(!T)	head->lchild=head;
	else{
		head->lchild=T;pre=head;
		InThreading(T);
	} 
}

//T为头结点 
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
	//测试样例
	//ABCD E   F  GHI   J K
	cout << "请输入建立二叉链表的序列：\n";
	createBiThrTree(tree);                 //建树
	InOrderThreading(head, tree);       //线索化
	cout << "中序遍历线索二叉树的结果为：\n";
	InOrderTraverse_Thr(head, visit);    //中序遍历线索二叉树
	cout << endl;
 
	system("pause");
	return 0;
}
