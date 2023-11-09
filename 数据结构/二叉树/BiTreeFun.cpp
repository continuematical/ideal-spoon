#include "QueueFun.cpp" 

//初始化一颗空的二叉树 
void InitBiTree(BiTree& T){
	T=NULL;
	return; 
}

//采取先序遍历构造二叉树 
void CreateBiTree(BiTree& T){
	char ch;cin>>ch;
	if(ch=='#')	T=NULL;
	else{
		T=new BiTNode();
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild); 
	}
}

bool BiTreeEmpty(BiTree& T){
	if(T==NULL)	return true;
	else	return false;
}

void BiTreeDepth(BiTree& T, int h, int& depth){
	if(T){
		if(h>depth)	depth=h;
		BiTreeDepth(T->lchild, h+1, depth);
		BiTreeDepth(T->rchild,h+1,depth);
	}
}

void preorder(BiTree& T){
	if(T){
		cout<<T->data;
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

void inorder(BiTree& T){
	if(T){
		preorder(T->lchild);
		cout<<T->data;
		preorder(T->rchild);
	}
}

void postorder(BiTree& T){
	if(T){
		preorder(T->lchild);
		preorder(T->rchild);
		cout<<T->data;
	}
}

BiTNode* LeftChild(BiTree& T, BiTNode* e){
	if(e->lchild==NULL)	return NULL;
	return e->lchild;
} 

BiTNode* RightChild(BiTree& T, BiTNode* e){
	if(e->rchild==NULL)	return NULL;
	return e->rchild;
}

BiTNode* Parent(BiTree& T, TElemType& e){
	LinkQueue q;
	BiTNode* p;
	if(T){
		InitQueue(q);EnQueue(q,T);
		while(!QueueEmpty(q)){
			DeQueue(q,p);
			if(p->lchild->data==e || p->rchild->data==e)	return p;
			else{
				if(p->lchild)	DeQueue(q,p->lchild);
				if(p->rchild)	DeQueue(q,p->rchild);
			}
		} 
	} 
	return NULL;
}

BiTNode* LeftSibling(BiTree& T, TElemType& e){
	BiTNode* p=Parent(T,e); 
	if(p==NULL||p->lchild->data==e)	return NULL;
	else	return p->lchild;
}

BiTNode* RightSibling(BiTree& T, TElemType& e){
	BiTNode* p=Parent(T,e); 
	if(p==NULL||p->rchild->data==e)	return NULL;
	else	return p->rchild;
}

void InsertChild(BiTree& T, TElemType& e){
	
}

void DeleteChild(BiTree& T, TElemType& e){
	
}
