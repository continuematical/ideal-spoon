#include "head.h"
#include "QueueFun.cpp"
using namespace std;
const int ITEM=9;

ElemType e,s;
LinkQueue Q;

ElemType flag=0;
ElemType InitialData=1;

//��ӡһ����������� 
//nΪ���� 
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

//��֪R[][]�Ǳ��0��n-1��n��Ԫ�صĹ�ϵ����
//�Լ����ֵĽ������result���飬result[k]��ֵ�Ǳ��Ϊk��Ԫ��������� 
void division(int R[][ITEM], int n, int result[]){
	//pre��ʾǰһ�γ����е���ţ�group��ʾ��ǰ����������� 
	int pre=n,group=0;
	InitQueue(Q);
	for(int e=0;e<n;e++)	EnQueue(Q,e);//����ֵ
	ElemType curr;
	int clash[ITEM];
	while(!QueueEmpty(Q)){
		DeQueue(Q,curr);//ȡ��һ��Ԫ��
		if(curr<=pre){//�����ǰԪ��С��ǰһ�������ʾ�����Ѿ�ѭ���������е�Ԫ�أ�Ӧ���½���һ����  
			++group;
			for(int i=0;i<n;i++)	clash[i]=0;
		}
		if(clash[curr]==0){
			result[curr]=group;
			for(int i=0;i<n;i++)	clash[i]+=R[curr][i];//��ӳ�ͻ��Ϣ 
		}else	EnQueue(Q,curr);//�����ͻ���Ǿͼ�����ջ 
		pre=curr;
	} 
}

int R[ITEM][ITEM] = {          //�þ��������洢�����ּ�����Ԫ��֮��ĳ�ͻ��ϵ��0������ͻ��1�����ͻ  
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
