#include "BiTreeFun.cpp"

int depth; 
char ch; 
vector<TElemType> s;
vector<TElemType> res; 

int main(){
	BiTree T;
	InitBiTree(T);
	CreateBiTree(T, s); //ABDH##I##EJ###CF##G##
	//AB#DE###C## 
	Traverse(T);
	printf("�����������������\n");
	preTraversal(T, res); 
	show(res);
	
	printf("�������Ĳ�α�����\n");
	res.clear();
	levelTraversal(T, res);
	show(res); 
	return 0;
} 
