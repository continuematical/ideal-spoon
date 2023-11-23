#include<bits/stdc++.h>
using namespace std;

const int N=10;//哈夫曼树总节点数目 
#define MAX 32767

typedef struct{
	char data;//节点的数据 
	unsigned int weight;//节点的权值 
	unsigned int parent, lchild, rchild;//节点的双亲，左孩子，右孩子 
}HTNode, *HuffmanTree;

void initHuffmanTree(HuffmanTree& HT){
	HT=(HTNode*)malloc(sizeof(HTNode)*2*N);
	for(int i=1;i<=2*N-1;i++){
		HT[i].parent=HT[i].lchild=HT[i].rchild=-1;//-1表示没有节点 
	} 
	printf("please input some weight!\n");
	for(int i=1;i<=N;i++)	scanf("%d", &HT[i].weight);
	char c=getchar();
	printf("please input some data!\n");
	for(int i=1;i<=N;i++){
		scanf("%c", &HT[i].data);
		char c=getchar();
	}
}

void createHuffmanTree(HuffmanTree& HT, int n){
	if(n<=1)	return;//如果节点数目小于1，不创建
	int lnode, rnode;
	for(int i=n+1;i<=2*n-1;i++){
		int min1=MAX;int lnode=-1;
		int min2=MAX;int rnode=-1;
		//遍历找到最小的两个节点 
		for(int j=1;j<=i-1;j++){
			if(HT[j].weight < min1 && HT[j].parent == -1){
				min2=min1;	rnode=lnode;
				min1=HT[j].weight; lnode=j;
			} else if(HT[j].weight < min2 && HT[j].parent == -1){
				min2=HT[j].weight;
				rnode=j;
			}
		}
		HT[lnode].parent=HT[rnode].parent=i;
		HT[i].lchild=lnode;
		HT[i].rchild=rnode;
		HT[i].weight=HT[lnode].weight+HT[rnode].weight;
	} 
}

void show(HuffmanTree& HT){
	for(int i=1;i<=n;i++){
		
	}
	cout<<endl;
}
