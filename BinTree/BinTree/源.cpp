#include<stdlib.h>
#include<stdio.h>
//可以根据实例定义类型
typedef char DataType;

typedef struct node {
	DataType data;
	node* lchild;
	node* rchild;
}BinTNode;

typedef BinTNode* BinTree;//BinTree为指向BinNode的指针类型

//中序遍历，栈
void InOrder(int num,BinTree root) {
	BinTree p;
	BinTree* s = (BinTree*)malloc(num * sizeof(BinTree));
	int top = -1;
	p = root;
	do {
		while (p) {
			s[++top] = p;
			p = p->lchild;//找到最后一个左孩子
		}

		if (top >= 0) {
			p = s[top--];
			p = p->rchild;
			printf("%c", p->data);
		}
	} while ((top == -1) && p == NULL);
}

//虚结点输入时以空格字符表示时，相应的构造方法
void CreateBinTree(BinTree* T) {
	char ch;
	if ((ch = getchar()) == ' ') {
		T = NULL;
	}
	else {
		*T = (BinTree)malloc(sizeof(BinTNode));
		(*T)->data = ch;
		CreateBinTree(&(*T)->lchild);//构造左子树
		CreateBinTree(&(*T)->rchild);//构造右子树
	}
}