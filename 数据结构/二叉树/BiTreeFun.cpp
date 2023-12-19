#include <bits/stdc++.h>
#include<windows.h>
using namespace std;

#define Status int
#define TElemType char
#define WType int 

#define OK 1
#define ERROR 0

const int N=100;

//------------�������Ķ�������洢��ʾ-------------
typedef struct BiTNode{
    TElemType data;
    WType weight;
    struct BiTNode *lchild, *rchild; //���Һ���ָ��
} BiTNode, *BiTree;

//------------���������ĺ���ԭ��˵��---------------
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
//-----------------����ʵ��-----------------------
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

//�����������
Status CreateBiTree(BiTree &T, vector<TElemType>& v){ 
    TElemType ch;
    scanf("%c", &ch);v.push_back(ch);
    if (ch == '#') 	T = NULL;
    else{
        T = (BiTree)malloc(sizeof(BiTNode));
        if (!T)
            exit(_OVERFLOW);
        T->data = ch; 
		T->weight = ch-'A';            
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
	if(!T)	return 0;
	else	return max(BiTreeDepth(T->lchild), BiTreeDepth(T->rchild))+1;
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
		printf("˫�׽ڵ�Ϊ��%c\n",T->data);
	    return 1;
	}
	else if(T->rchild&&T->rchild->data==e){
		printf("˫�׽ڵ�Ϊ��%c\n",T->data);
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
		printf("���ӽڵ�Ϊ��%c\n",T->lchild->data);
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
		printf("�Һ��ӽڵ�Ϊ��%c\n",T->rchild->data);
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
		printf("���ֵܽڵ�Ϊ��%c\n",T->lchild->data);
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
		printf("���ֵܽڵ�Ϊ��%c\n",T->rchild->data);
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
	if(LR==0){//c��������Ϊ�գ�ʹp����������Ϊc������������ʹ��������������c��Ϊp�������� 
		c->rchild=p->lchild;
		p->lchild=c;
	}
	else{//c��������Ϊ�գ�ʹp����������Ϊc������������ʹ��������������c��Ϊp�������� 
		c->rchild=p->rchild;
		p->rchild=c;
	}
	return 1; 
}

Status DeleteChild(BiTree T,BiTree p,int LR){
	if(LR==0){//ɾ��p�������� 
		DestroyBiTree(p->lchild); 
	}
	else{//ɾ��p�������� 
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

//�ı���λ��
void gotoxy(int x, int y)
{
	// ���¹��λ��
	COORD pos;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOutput, pos);
}

//������Ϊ�������������� 
Status breakTree(BiTree& T, BiTNode*& L, BiTNode*& R){
	if(T==NULL)	return 0;
	L=T->lchild;
	R=T->rchild;
	return 1; 
}

BiTNode* L,R;

/*
* �ݹ��ӡ��ӡ������
* T		���ڴ�ӡ����
* depth	Ŀǰ�ڴ�ӡ���ĵڼ���
* right	�������Ƿ�Ϊ������
* tap	Ŀǰ������Ҫ�����ƫ������
*/
Status Traverse_R(BiTree T, int depth, int right, int tap, int h) {
	if (T == NULL) return 1;

	// ��ȡһ�����ĳ�ʼ�߶ȣ����ڼ������ƫ������
	static int treeDepth = BiTreeDepth(T);
	// ��¼��ǰ���λ�ã������ڵݹ��м�¼��ǰ�ݹ�ʱ����λ��
	int x, y;
	// �����������������������ֿ���
	BiTree L, R;
	breakTree(T, L, R);

	// ���㸸����ƫ����
	int tap1 = tap*pow(2, treeDepth-depth);
	// ����������ƫ����
	int tap2 = right*(pow(2, treeDepth- depth));
	// �����ƫ����
	int tap3 = pow(2, treeDepth-depth-1);

	// ��ȡ��������
	x = tap1+tap2+tap3;
	y = depth*2+h;

	// ��ӡ����λ��
	gotoxy(x*2, y);
	printf("%c", T->data);

	// �ڴ�ӡ����ʱ����ǰ����+1
	depth++;
	// ���������ĸ�ƫ����
	tap=tap*2+(right==1?2:0);
	if (L==NULL&&R==NULL) return 1;
	else if (R==NULL) {
		// ��ӡ��������λ��
		gotoxy(x*2-tap3,y+1);
		printf("��");
		for (int i=0;i<tap3-1; i++) printf("��");
		printf("��");
		Traverse_R(L,depth,0,tap, h);
	} else if (L==NULL) {
		// ��ӡ��������λ��
		gotoxy(x*2, y+1);
		printf("��");
		for (int i = 0;i<tap3-1; i++) printf("��");
		printf("��");
		Traverse_R(R,depth,1,tap, h);
	} else {
		// ��ӡ����������λ��
		gotoxy(x*2-tap3, y+1);
		printf("��");
		for (int i = 0; i<tap3-1; i++) printf("��");
		printf("��");
		for (int i = 0; i<tap3-1; i++) printf("��");
		printf("��");
		Traverse_R(L, depth, 0, tap, h);
		Traverse_R(R, depth, 1, tap, h);
	}
}

// ��ӡ���νӿ�
Status Traverse(BiTree& T, int h) {
	Traverse_R(T, 0, 0, 0, h);
	int x=0;int y=BiTreeDepth(T)*3+3; 
	gotoxy(x,y);
	return 1;
}

//�жϴ����Ƿ�Ϊƽ������� 
Status isBalancedTree(BiTree T){
	if(T==NULL)	return OK;
	int leftDepth=BiTreeDepth(T->lchild);
	int rightDepth=BiTreeDepth(T->rchild);
	if(abs(leftDepth-rightDepth)>1)	return ERROR;
	else{
		Status left=isBalancedTree(T->lchild);
		Status right=isBalancedTree(T->rchild);
		if(left && right)	return OK;	
	}
	return OK; 
} 

//�жϽ������ 
Status countNode(BiTree& T, int& count){
	if(T){
		count++;
		countNode(T->lchild, count);
		countNode(T->rchild, count);
	}
}

//�ݹ�
void get_paths(BiTree& T, vector<string>& res, string path){
	if(T){
		path+=T->data;
		if(T->lchild==NULL && T->rchild==NULL){
			res.push_back(path);
			return;
		}else{
			get_paths(T->lchild, res, path);
			get_paths(T->rchild, res, path);
		}
	}
} 

//��������Ӹ��ڵ㵽Ҷ�ӽ�������·�� 
void BiTreePaths(BiTree& T, vector<string>& res){
	get_paths(T, res, "");
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<endl;
} 

//���WPL
void BiTreeWPL(BiTree& T, int deep, int& WPL){
	if(T){
		if(!T->lchild && !T->rchild){
			WPL+=deep*T->weight;
		} else {
			BiTreeWPL(T->lchild, deep+1, WPL);
			BiTreeWPL(T->rchild, deep+1, WPL); 
		} 
	}
} 

//���������������Һ���
void swap(BiTree& T){
	//������û�����ҽڵ� 
	if(!T->lchild && !T->rchild)	return;
	BiTree temp;
	temp=T->lchild;
	T->lchild=T->rchild;
	T->rchild=temp;
	if(T->lchild)	swap(T->lchild);
	if(T->rchild)	swap(T->rchild);
} 
