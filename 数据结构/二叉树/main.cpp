#include "BiTreeFun.cpp"

int depth; 
BiTNode* p;char ch; 

int main(){
	BiTree T;
	InitBiTree(T);
	CreateBiTree(T); //AB#DE###C##
	BiTreeDepth(T,1,depth);
	printf("树的层次为："); 
	cout<<depth<<endl;
	getchar(); 
	scanf("%c",&ch);
	p=Parent(T,ch);
	if(p==NULL) cout<<"无双亲节点"<<endl;
	else	cout<<p->data<<endl;
	getchar();
	scanf("%c",&ch);
	p=LeftSibling(T,ch);
	if(p==NULL) cout<<"无右孩子节点"<<endl;
	else	cout<<p->data<<endl;
	
	return 0;
} 
