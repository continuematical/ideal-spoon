#include "head.h"
#include "ErrorMessage.cpp"

typedef struct{
	ElemType* elem;//�洢Ԫ�ص�һά���� 
	int length;//���Ա���
	int listSize;//��ǰ��������Ա�����
	int incrementSize;//Լ���������ռ� 
}SqList; 

//�����ռ�
void incrementList(SqList &L){
	//Ϊ˳�������Ԫ�ؿռ�
	ElemType a[L.listSize+L.incrementSize];
	//ת��Ԫ��
	for(int i=0;i<L.length;i++){
		a[i]=L.elem[i];
	} 
	free(L.elem);
	L.elem=a;
	L.listSize+=L.incrementSize;
}

//1.��ʼ�����Ա� 
void InitList(SqList &L){
	L.elem=new ElemType[LIST_INIT_SIZE];
	L.listSize=LIST_INIT_SIZE;
	L.incrementSize=LISTINCREMENT;
	L.length=0;
}

//2.�������Ա�
void DestroyList(SqList L){
	free(L.elem);
} 

//4.�Ƿ�Ϊ�ձ� 
int ListEmpty(SqList L){
	if(L.length==0)	return true;
	else return false;
} 

//5.L��Ԫ�ظ��� 
int ListLength(SqList L){
	return L.length;
} 

//6.��e����L�е�i��Ԫ�ص�ֵ
void GetElem(SqList L, int i, ElemType &e){
	if(i<1||i>L.length){
		ErrorMessage("iֵ���Ϸ�");
		return;
	}
	e=L.elem[i-1];
} 

//7.����Ԫ�ز���
int LocateElem(SqList L, ElemType e){
	int i=1;//��ʼλ��
	ElemType* p=L.elem;//������ʼ��ַ
	while(i<=L.length && *p++!=e)	i++;
	if(i<=L.length)	return i;
	else	return 0;//���û�и�Ԫ�أ��򷵻� 0
}

//10.����Ԫ�ز���
void ListInsert(SqList &L,int i,ElemType e){
	//�ڵ�i��Ԫ��֮������µ�Ԫ��
	if(i<1||i>L.length+1)	ErrorMessage("iֵ���Ϸ�");
	//������Ա�Ԫ�ش������Ա����� 
	if(L.length>=L.listSize)	incrementList(L); 
	ElemType* p=&(L.elem[i-1]);
	//��βԪ��λ��
	ElemType* q=L.elem+L.length-1;
	//Ԫ������
	for(;q>=p;q--)	*q=*(q-1);
	*p=e;
	L.length+=1;
}

//11.ɾ��Ԫ�ز���
void ListDelete(SqList &L,int i, ElemType &e){
	if(i<1 || i>L.length+1)	ErrorMessage("iֵ���Ϸ�");
	ElemType* p=&(L.elem[i-1]);//Ҫɾ��Ԫ�ص�λ��
	e=*p;//��ɾ��Ԫ�ظ�ֵ��e
	//��βԪ��λ��
	ElemType* q=L.elem+L.length-1;
	//Ԫ������
	for(++p;p<=q;++p)	*(p-1)=*p;
	L.length-=1; 
} 

//12.�������L��ÿ������Ԫ�� 
void ListTraverse(SqList L){
	for(int i=0;i<L.length;i++){
		printf("%d ",L.elem[i]); 
	}
}
