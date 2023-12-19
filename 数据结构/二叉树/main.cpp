#include "BiTreeFun.cpp"

int num=0; 
char ch; 
vector<TElemType> s;
vector<TElemType> res; 
vector<string> path;

void BiTreeTest(){
	BiTree T;
	InitBiTree(T);
	printf("请输入节点：");
	CreateBiTree(T, s); //ABDH##I##EJ###CF##G##
	//AB#DE###C## 
	Traverse(T, 1);
	
	swap(T);
	Traverse(T, 2*BiTreeDepth(T));
		
	printf("二叉树的深度：\n");
	cout<<BiTreeDepth(T)<<endl;
	printf("二叉树的中序遍历：\n");
	preTraversal(T, res); 
	show(res);
	
	printf("二叉树的层次遍历：\n");
	res.clear();
	levelTraversal(T, res);
	show(res); 
	
	printf("二叉树的节点个数：\n");
	countNode(T, num);
	cout<<num<<endl;
	
	printf("判断是否为平衡二叉树：\n");
	if(isBalancedTree(T))	printf("Yes\n");
	else	printf("No");
	
	printf("遍历输出二叉树的所有路径：\n");
	BiTreePaths(T, path); 
	
	printf("带权路径长度为：\n");
	int WPL=0;
	BiTreeWPL(T, 1, WPL);
	cout<<WPL<<endl;
}

int main(){
	BiTreeTest();
	return 0;
} 
