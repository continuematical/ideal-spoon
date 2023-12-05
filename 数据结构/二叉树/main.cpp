#include "BiTreeFun.cpp"

int depth; 
char ch; 
vector<TElemType> s;
vector<TElemType> res; 

void BiTreeTest(){
	BiTree T;
	InitBiTree(T);
	CreateBiTree(T, s); //ABDH##I##EJ###CF##G##
	//AB#DE###C## 
	Traverse(T);
	printf("二叉树的深度：\n");
	cout<<BiTreeDepth(T)<<endl;
	printf("二叉树的中序遍历：\n");
	preTraversal(T, res); 
	show(res);
	
	printf("二叉树的层次遍历：\n");
	res.clear();
	levelTraversal(T, res);
	show(res); 
}

int main(){
	BiTreeTest();
	return 0;
} 
