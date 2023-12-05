#include<bits/stdc++.h>
using namespace std;

const int N=10;//���������ܽڵ���Ŀ 
#define MAX 32767

typedef struct{
	char data;//�ڵ������ 
	unsigned int weight;//�ڵ��Ȩֵ 
	unsigned int parent, lchild, rchild;//�ڵ��˫�ף����ӣ��Һ��� 
}HTNode, *HuffmanTree;

typedef char** HuffmanCode;

void initHuffmanTree(HuffmanTree& HT){
	HT=(HTNode*)malloc(sizeof(HTNode)*2*N);
	for(int i=1;i<=2*N-1;i++)	HT[i].parent=HT[i].lchild=HT[i].rchild=-1;//-1��ʾû�нڵ� 
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
	if(n<=1)	return;//����ڵ���ĿС��1��������
	int lnode, rnode;
	for(int i=n+1;i<=2*n-1;i++){
		int min1=MAX;int lnode=-1;
		int min2=MAX;int rnode=-1;
		//�����ҵ���С�������ڵ� 
		//�ڵ�ֵ�洢��min1��min2�У��ڵ�λ�ô洢��lnode��rnode�� 
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

//�����շ�����HT����n��Ҷ�ӽڵ�ı������HC 
void createHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n)
{
	HC = (HuffmanCode)malloc(sizeof(HuffmanCode) * n + 1);				//����n + 1��huffmanCode��СhuffmanCode���͵���ʱ�ռ�
																		//��Ϊ�±��Ǵ�һ��ʼ����������Ҫ����Ƚ���һ���Ľ�㣬�͹��������Ľṹ��Ӧ���������
	char* cd = (char*)malloc(sizeof(char) * n);							//����n��char��Сchar���͵���ʱ�ռ䣬�����ʱ�����¼ÿ�α��������ı���
	int start = 0,c = 0,f = 0;											//startΪcd�����¼�±꣬c��ʼΪҶ�ӽ���±꣬������Ǻ��ӽ����±꣬f��¼˫�׽����±�
	cd[n - 1] = '\0';													//������Ǹ�printf���ŵģ���Ϊprintf��������'\0'�������puts�Ͳ�����������
	for (int i=1;i<=n;i++){										//ֻҪҶ�ӽ��ı���
		start=n-1;													//���Ҫ��ֵn�Ļ���start--Ҫд���жϺ�
		c=i;	
		f=HT[c].parent;
		while (f!=-1)	{												//���ڵ�û��˫��
			start--;
			if (HT[f].lchild==c)											//�����Ӿ���0���Һ��Ӿ�Ϊ1
				cd[start] = '0';
			else	cd[start] = '1';
			c=f; f = HT[c].parent;									//������ӽ�
		}
		HC[i] = (char*)malloc(sizeof(char) * (n - start));				//�����������������n - start��char��С��char*���͵���ʱ�ռ�
		strcpy(HC[i], &cd[start]);										//cd���¼�ı����HC�ĵ�i������
	}
	free(cd);															//�ͷ���ʱ�ռ�
}


void showHuffmanCode(HuffmanTree& HT, HuffmanCode& HC){
	for(int i=1;i<=N;i++){
		printf("%c:", HT[i].data);
		printf("%s\n", HC[i]);
	}
}

