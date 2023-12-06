#include "BiTreeFun.cpp"

int num=0; 
char ch; 
vector<TElemType> s;
vector<TElemType> res; 

void BiTreeTest(){
	BiTree T;
	InitBiTree(T);
	CreateBiTree(T, s); //ABDH##I##EJ###CF##G##
	//AB#DE###C## 
	Traverse(T);
	printf("����������ȣ�\n");
	cout<<BiTreeDepth(T)<<endl;
	printf("�����������������\n");
	preTraversal(T, res); 
	show(res);
	
	printf("�������Ĳ�α�����\n");
	res.clear();
	levelTraversal(T, res);
	show(res); 
	
	printf("�������Ľڵ������\n");
	countNode(T, num);
	cout<<num<<endl;
}

int main(){
	BiTreeTest();
	return 0;
} 
