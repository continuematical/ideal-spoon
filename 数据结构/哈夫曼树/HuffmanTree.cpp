#include<bits/stdc++.h>
using namespace std;

const int N=10;//哈夫曼树总节点数目 
#define MAX 32767

typedef struct{
	char data;//节点的数据 
	unsigned int weight;//节点的权值 
	unsigned int parent, lchild, rchild;//节点的双亲，左孩子，右孩子 
}HTNode, *HuffmanTree;

typedef char** HuffmanCode;

void initHuffmanTree(HuffmanTree& HT){
	HT=(HTNode*)malloc(sizeof(HTNode)*2*N);
	for(int i=1;i<=2*N-1;i++)	HT[i].parent=HT[i].lchild=HT[i].rchild=-1;//-1表示没有节点 
	printf("please input some weight!\n");
	for(int i=1;i<=N;i++)	scanf("%d", &HT[i].weight);
	char c=getchar();
	printf("please input some data!\n");
	for(int i=1;i<=N;i++){
		char c=getchar();
		if(c=='\n')	break;
		else	HT[i].data=c; 
	}
}

void createHuffmanTree(HuffmanTree& HT, int n){
	if(n<=1)	return;//如果节点数目小于1，不创建
	int lnode, rnode;
	for(int i=n+1;i<=2*n-1;i++){
		int min1=MAX;int lnode=-1;
		int min2=MAX;int rnode=-1;
		//遍历找到最小的两个节点 
		//节点值存储在min1，min2中，节点位置存储在lnode，rnode中 
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

//遍历赫夫曼树HT，将n个叶子节点的编码存入HC 
void createHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n)
{
	HC = (HuffmanCode)malloc(sizeof(HuffmanCode) * n + 1);				//申请n + 1个huffmanCode大小huffmanCode类型的临时空间
																		//因为下标是从一开始，所以我们要申请比结点多一个的结点，和哈夫曼树的结构对应，方便输出
	char* cd = (char*)malloc(sizeof(char) * n);							//申请n个char大小char类型的临时空间，这个临时数组记录每次遍历出来的编码
	int start = 0,c = 0,f = 0;											//start为cd数组记录下标，c初始为叶子结点下标，而后就是孩子结点的下标，f记录双亲结点的下标
	cd[n - 1] = '\0';													//这个就是给printf留着的，因为printf不会生成'\0'，如果用puts就不用这句语句了
	for (int i=1;i<=n;i++){										//只要叶子结点的编码
		start=n-1;													//这句要赋值n的话，start--要写在判断后方
		c=i;	
		f=HT[c].parent;
		while (f!=-1)	{												//根节点没有双亲
			start--;
			if (HT[f].lchild==c)											//是左孩子就是0，右孩子就为1
				cd[start] = '0';
			else	cd[start] = '1';
			c=f; f = HT[c].parent;									//向根结点接近
		}
		HC[i] = (char*)malloc(sizeof(char) * (n - start));				//给数组里的数组申请n - start个char大小的char*类型的临时空间
		strcpy(HC[i], &cd[start]);										//cd里记录的编码给HC的第i个数组
	}
	free(cd);															//释放临时空间
}


void showHuffmanCode(HuffmanTree& HT, HuffmanCode& HC){
	for(int i=1;i<=N;i++){
		printf("%c:", HT[i].data);
		printf("%s\n", HC[i]);
	}
}

