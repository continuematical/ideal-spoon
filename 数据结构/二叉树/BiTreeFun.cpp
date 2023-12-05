#include <bits/stdc++.h>
#include<windows.h>
using namespace std;

#define Status int
#define TElemType char
#define OK 1
#define ERROR 0

const int N=100;

//------------二叉树的二叉链表存储表示-------------
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild; //左右孩子指针
} BiTNode, *BiTree;

//------------基本操作的函数原型说明---------------
Status InitBiTree(BiTree &T);
Status DestroyBiTree(BiTree &T);
Status CreateBiTree(BiTree &T);
void ClearBiTree(BiTree &T);
Status BiTreeEmpty(BiTree T);
int BiTreeDepth(BiTree T);
Status Root(BiTree T);
Status Value(BiTree T, TElemType e);
Status Assign(BiTree &T, TElemType e, TElemType value);
Status Parent(BiTree T, TElemType e);
Status LeftChild(BiTree T, TElemType e);
Status RightChild(BiTree T, TElemType e);
Status LeftSibling(BiTree T, TElemType e);
Status RightSibling(BiTree T, TElemType e);
Status InsertChild(BiTree T, BiTree p, int LR, BiTree c);
Status DeleteChild(BiTree T, BiTree p, int LR);
//-----------------具体实现-----------------------
Status InitBiTree(BiTree &T){
    T = NULL;
    return 1;
}

Status DestroyBiTree(BiTree &T){
    if ((T)->lchild)             
        DestroyBiTree(T->lchild); 
    if ((T)->rchild)                 
        DestroyBiTree(T->rchild); 
    free(T);                        
    T = NULL;
    return 1;
}

//中序遍历建树
Status CreateBiTree(BiTree &T, vector<TElemType>& v){ 
    TElemType ch;
    scanf("%c", &ch);v.push_back(ch);
    if (ch == '#') 	T = NULL;
    else{
        T = (BiTree)malloc(sizeof(BiTNode));
        if (!T)
            exit(_OVERFLOW);
        T->data = ch;             
        CreateBiTree(T->lchild, v); 
        CreateBiTree(T->rchild, v);
    }
    return 1;
}

void ClearBiTree(BiTree &T){
    if (T){
        if (T->lchild)    ClearBiTree(T->lchild); 
        if (T->rchild)    ClearBiTree(T->rchild); 
        free(T);                        
        T = NULL;                
    }
}

Status BiTreeEmpty(BiTree T){
    if (T)	return 0;
    else	return 1;
}

int BiTreeDepth(BiTree T){
    int i, j;
    if (!T)	return 0;
    if (T->lchild)	i = BiTreeDepth(T->lchild);
    else	i = 0;
    if (T->rchild)	j = BiTreeDepth(T->rchild);
    else	j = 0;
    return i > j ? i + 1 : j + 1;
}

Status Root(BiTree T){
    cout << T->data << endl;
    return 1;
}

Status Value(BiTree T,TElemType e){
    if(T->data==e)	return 1;
    else{
        int i = 0, j = 0;
        if(T->lchild)
            i = Value(T->lchild, e);
        if(T->rchild)
            j = Value(T->rchild, e);
        if(i||j)
            return 1;
        else
            return 0;
    }
    return 0;
}

Status Assign(BiTree &T,TElemType e,TElemType value){
	if(T->data==e){
        T->data = value;
        return 1;
	}
	else{
		int i=0,j=0;
		if(T->lchild){
            i = Assign(T->lchild, e, value);
        }
		if(T->rchild){
			j=Assign(T->rchild,e,value);
		}
		if(i||j) return 1;
		else return 0;
	}
	return 0;
}

Status Parent(BiTree T,TElemType e){
	if(T->lchild&&T->lchild->data==e){
		printf("双亲节点为：%c\n",T->data);
	    return 1;
	}
	else if(T->rchild&&T->rchild->data==e){
		printf("双亲节点为：%c\n",T->data);
	    return 1;
	}
	else{
		if(T->lchild)	Parent(T->lchild,e);
		if(T->rchild)	Parent(T->rchild,e);
	}
	return 0;
}

Status LeftChild(BiTree T,TElemType e){
	if(T->data==e&&T->lchild){
		printf("左孩子节点为：%c\n",T->lchild->data);
		return 1;
	}
	else{
		if(T->lchild){
			LeftChild(T->lchild,e);
		}
		if(T->rchild){
			LeftChild(T->rchild,e);
		}
	}
	return 0;
}

Status RightChild(BiTree T,TElemType e){
	if(T->data==e&&T->rchild){
		printf("右孩子节点为：%c\n",T->rchild->data);
		return 1;
	}
	else{
		if(T->lchild){
			RightChild(T->lchild,e);
		}
		if(T->rchild){
			RightChild(T->rchild,e);
		}
	}
	return 0;
}

Status LeftSibling(BiTree T,TElemType e){
	if(T->lchild&&T->rchild->data==e){
		printf("左兄弟节点为：%c\n",T->lchild->data);
		return 1;
	}
	else{
		if(T->lchild)	LeftSibling(T->lchild,e); 
		if(T->rchild)	LeftSibling(T->rchild,e);
	}
	return 0;
}

Status RightSibling(BiTree T,TElemType e){
	if(T->rchild&&T->lchild->data==e){
		printf("左兄弟节点为：%c\n",T->rchild->data);
		return 1;
	}
	else{
		if(T->lchild){
			RightSibling(T->lchild,e);
		}
		if(T->rchild){
			RightSibling(T->rchild,e);
		}
	}
	return 0;
}

Status InsertChild(BiTree T,BiTree p,int LR,BiTree c){
	if(LR==0){//c的右子树为空，使p的左子树成为c的右子树，并使增加了右子树的c成为p的左子树 
		c->rchild=p->lchild;
		p->lchild=c;
	}
	else{//c的右子树为空，使p的右子树成为c的右子树，并使增加了右子树的c成为p的右子树 
		c->rchild=p->rchild;
		p->rchild=c;
	}
	return 1; 
}

Status DeleteChild(BiTree T,BiTree p,int LR){
	if(LR==0){//删除p的左子树 
		DestroyBiTree(p->lchild); 
	}
	else{//删除p的右子树 
		DestroyBiTree(p->rchild);
	}
	return 1; 
}

Status preTraversal(BiTree T, vector<TElemType>& res){
	if(T!=NULL){
		res.push_back(T->data);
		preTraversal(T->lchild, res);
		preTraversal(T->rchild, res);
	}
	return 1;
}

Status postTraversal(BiTree T, vector<TElemType>& res){
	if(T!=NULL){
		postTraversal(T->lchild, res);
		postTraversal(T->rchild, res);
		res.push_back(T->data);
	}
	return 1;
}

Status inTraversal(BiTree T, vector<TElemType>& res){
	if(T!=NULL){
		inTraversal(T->lchild, res);
		res.push_back(T->data); 
		inTraversal(T->rchild, res);
	}
	return 1;
}

Status levelTraversal(BiTree T, vector<TElemType>& res){
	queue<BiTNode*> q;
	if(T==NULL)	return 0;
	q.push(T);
	while(!q.empty()){
		BiTNode* p=q.front();q.pop();
		res.push_back(p->data);
		if(p->lchild!=NULL)	q.push(p->lchild);
		if(p->rchild!=NULL)	q.push(p->rchild);
	}
	return 1;
} 

void show(vector<TElemType> res){
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	cout<<endl; 
}

//改变光标位置
void gotoxy(int x, int y)
{
	// 更新光标位置
	COORD pos;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOutput, pos);
}

//将树分为左子树和右子树 
Status breakTree(BiTree& T, BiTNode*& L, BiTNode*& R){
	if(T==NULL)	return 0;
	L=T->lchild;
	R=T->rchild;
	return 1; 
}

BiTNode* L,R;

/*
* 递归打印打印出树形
* T		正在打印的树
* depth	目前在打印树的第几层
* right	该子树是否为右子树
* tap	目前子树需要的相对偏移数量
*/
Status Traverse_R(BiTree T, int depth, int right, int tap) {
	if (T == NULL) return 1;

	// 获取一次树的初始高度，用于计算相对偏移数量
	static int treeDepth = BiTreeDepth(T);
	// 记录当前光标位置，用于在递归中记录当前递归时树的位置
	int x, y;
	// 拆分树，将树的左右子树拆分开来
	BiTree L, R;
	breakTree(T, L, R);

	// 计算父树的偏移量
	int tap1 = tap*pow(2, treeDepth-depth);
	// 计算子树的偏移量
	int tap2 = right*(pow(2, treeDepth- depth));
	// 计算半偏移量
	int tap3 = pow(2, treeDepth-depth-1);

	// 获取根的坐标
	x = tap1+tap2+tap3;
	y = depth*2+1;

	// 打印根的位置
	gotoxy(x*2, y);
	printf("%c", T->data);

	// 在打印子树时，当前层数+1
	depth++;
	// 计算子树的父偏移量
	tap=tap*2+(right==1?2:0);
	if (L==NULL&&R==NULL) return 1;
	else if (R==NULL) {
		// 打印左子树的位置
		gotoxy(x*2-tap3,y+1);
		printf("┏");
		for (int i=0;i<tap3-1; i++) printf("━");
		printf("┛");
		Traverse_R(L,depth,0,tap);
	} else if (L==NULL) {
		// 打印右子树的位置
		gotoxy(x*2, y+1);
		printf("┗");
		for (int i = 0;i<tap3-1; i++) printf("━");
		printf("┓");
		Traverse_R(R,depth,1,tap);
	} else {
		// 打印左右子树的位置
		gotoxy(x*2-tap3, y+1);
		printf("┏");
		for (int i = 0; i<tap3-1; i++) printf("━");
		printf("┻");
		for (int i = 0; i<tap3-1; i++) printf("━");
		printf("┓");
		Traverse_R(L, depth, 0, tap);
		Traverse_R(R, depth, 1, tap);
	}
}

// 打印树形接口
Status Traverse(BiTree T) {
	Traverse_R(T, 0, 0, 0);
	int x=0;int y=BiTreeDepth(T)*2+1; 
	gotoxy(x,y);
	return 1;
}
