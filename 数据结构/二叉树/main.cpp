#include "BiTreeFun.cpp"

int depth; 
BiTNode* p;char ch; 

int main(){
	BiTree T;
	InitBiTree(T);
	CreateBiTree(T); //AB#DE###C##
	BiTreeDepth(T,1,depth);
	printf("���Ĳ��Ϊ��"); 
	cout<<depth<<endl;
	getchar(); 
	scanf("%c",&ch);
	p=Parent(T,ch);
	if(p==NULL) cout<<"��˫�׽ڵ�"<<endl;
	else	cout<<p->data<<endl;
	getchar();
	scanf("%c",&ch);
	p=LeftSibling(T,ch);
	if(p==NULL) cout<<"���Һ��ӽڵ�"<<endl;
	else	cout<<p->data<<endl;
	
	return 0;
} 
