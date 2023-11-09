#include "head.h"
#include "QueueFun.cpp"
using namespace std;
const int ITEM=9;

ElemType e,s;
LinkQueue Q;

ElemType flag=0;
ElemType InitialData=1;

//打印一个杨辉三角形 
//n为层数 
void YangHui(int n){
	InitQueue(Q);
	for(int i=0;i<n;i++)	cout<<' ';
	cout<<"1"<<endl;
	EnQueue(Q,flag);
	EnQueue(Q,InitialData);
	EnQueue(Q,InitialData);
	for(int i=1;i<n;i++){
		for(int k=0;k<n-i;k++)	cout<<' ';
		EnQueue(Q,flag);
		do{
			DeQueue(Q,s);
			GetHead(Q,e);
			if(e)	cout<<e<<' ';
			else	cout<<endl;
			ElemType data=e+s;
			EnQueue(Q,data);
		}while(e!=0);
	}
	DeQueue(Q,e);
	QueueTraverse(Q);
} 

//已知R[][]是编号0至n-1的n个元素的关系矩阵
//自己划分的结果记入result数组，result[k]的值是编号为k的元素所属组号 
void division(int R[][ITEM], int n, int result[]){
	//pre表示前一次出队列的序号，group表示当前分配的组的序号 
	int pre=n,group=0;
	InitQueue(Q);
	for(int e=0;e<n;e++)	EnQueue(Q,e);//赋初值
	ElemType curr;
	int clash[ITEM];
	while(!QueueEmpty(Q)){
		DeQueue(Q,curr);//取出一个元素
		if(curr<=pre){//如果当前元素小于前一个，则表示队列已经循环遍历所有的元素，应该新建另一个组  
			++group;
			for(int i=0;i<n;i++)	clash[i]=0;
		}
		if(clash[curr]==0){
			result[curr]=group;
			for(int i=0;i<n;i++)	clash[i]+=R[curr][i];//添加冲突信息 
		}else	EnQueue(Q,curr);//如果冲突，那就继续入栈 
		pre=curr;
	} 
}

int R[ITEM][ITEM] = {          //该矩阵用来存储待划分集合中元素之间的冲突关系，0代表不冲突，1代表冲突  
{0, 1, 0, 0, 0, 1, 0, 0, 0},  
{1, 0, 0, 0, 1, 1, 0, 1, 1},  
{0, 0, 0, 0, 0, 1, 1, 0, 0},  
{0, 0, 0, 0, 1, 0, 0, 0, 1},  
{0, 1, 0, 1, 0, 0, 1, 0, 1},  
{1, 1, 1, 0, 0, 0, 1, 0, 0},  
{0, 0, 1, 0, 1, 1, 0, 0, 0},  
{0, 1, 0, 0, 0, 0, 0, 0, 0},  
{0, 1, 0, 1, 1, 0, 0, 0, 0}};  

int result[ITEM];

int main() {
	division(R,ITEM,result);
	for(int i=0;i<ITEM;i++){
		cout<<result[i]<<" ";
	}
	cout<<endl;
	return 0;
}
