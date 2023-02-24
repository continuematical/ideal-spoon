#include<stdlib.h>
#include<stdio.h>
//���Ը���ʵ����������
typedef char DataType;

typedef struct node {
	DataType data;
	node* lchild;
	node* rchild;
}BinTNode;

typedef BinTNode* BinTree;//BinTreeΪָ��BinNode��ָ������

//���������ջ
void InOrder(int num,BinTree root) {
	BinTree p;
	BinTree* s = (BinTree*)malloc(num * sizeof(BinTree));
	int top = -1;
	p = root;
	do {
		while (p) {
			s[++top] = p;
			p = p->lchild;//�ҵ����һ������
		}

		if (top >= 0) {
			p = s[top--];
			p = p->rchild;
			printf("%c", p->data);
		}
	} while ((top == -1) && p == NULL);
}

//��������ʱ�Կո��ַ���ʾʱ����Ӧ�Ĺ��췽��
void CreateBinTree(BinTree* T) {
	char ch;
	if ((ch = getchar()) == ' ') {
		T = NULL;
	}
	else {
		*T = (BinTree)malloc(sizeof(BinTNode));
		(*T)->data = ch;
		CreateBinTree(&(*T)->lchild);//����������
		CreateBinTree(&(*T)->rchild);//����������
	}
}