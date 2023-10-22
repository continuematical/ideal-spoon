#include "head.h"
#include "ErrorMessage.cpp"

typedef struct{
	ElemType* elem;//�洢Ԫ�ص�һά���� 
	int length;//���Ա���
	int listSize;//��ǰ��������Ա�����
	int incrementSize;//Լ���������ռ� 
}SqList; 

//�����ռ�
Status incrementList(SqList &L){
	//Ϊ˳�������Ԫ�ؿռ�
	ElemType a[L.listSize+L.incrementSize];
	//ת��Ԫ��
	for(int i=0;i<L.length;i++){
		a[i]=L.elem[i];
	} 
	free(L.elem);
	L.elem=a;
	//�������� 
	L.listSize+=L.incrementSize;
	return OK;
}

//1.��ʼ�����Ա� 
Status InitList(SqList &L){
	L.elem=new ElemType[LIST_INIT_SIZE];
	L.listSize=LIST_INIT_SIZE;
	L.incrementSize=LISTINCREMENT;
	L.length=0;
	return OK;
} 

//2.�������Ա�
Status DestroyList(SqList L){
	delete[] L.elem;
	L.length=0;
	L.listSize=0;
	return OK;
} 

//3.������Ա�
Status clearList(SqList &L){
	for(int i=0;i<L.length;i++){
		L.elem[i]=0;
	}
	L.length=0;
	return OK;
}

//4.�Ƿ�Ϊ�ձ� 
int ListEmpty(SqList L){
	if(L.elem!=NULL){
		if(L.length==0)	return true;
		else return false;	
	} else{
		ErrorMessage("δ��ʼ��\n");
	}
} 

//5.L��Ԫ�ظ��� 
int ListLength(SqList L){
	if(L.elem!=NULL){
		return L.length;	
	}else{
		ErrorMessage("δ��ʼ��\n");
	}
} 

//6.��e����L�е�i��Ԫ�ص�ֵ
Status GetElem(SqList L, int i, ElemType &e){
	if(i<1||i>L.length){
		ErrorMessage("iֵ���Ϸ�");
		return ERROR;
	}
	e=L.elem[i-1];
	return OK;
} 

//7.����Ԫ�ز���
int LocateElem(SqList L, ElemType e){
	int i=1;//��ʼλ��
	ElemType* p=L.elem;//������ʼ��ַ
	while(i<=L.length && *p++!=e)	i++;
	if(i<=L.length)	return i;
	else	return 0;//���û�и�Ԫ�أ��򷵻� 0
}

//8.����Ԫ�ص�ǰ�� 
Status PriorElem(SqList L, ElemType cur_e, ElemType& pre_e){
	if(L.elem==NULL || LocateElem(L,cur_e)==1)	return ERROR; 
	int i=LocateElem(L,cur_e);
	pre_e=L.elem[i-2];
	return OK;
}

//9.����Ԫ�صĺ�� 
Status NextElem(SqList L, ElemType cur_e, ElemType& next_e){
	if(L.elem==NULL || LocateElem(L,cur_e)==L.length)	return ERROR;
	int i=LocateElem(L,cur_e);
	next_e=L.elem[i];
	return OK;
}

//10.����Ԫ�ز���
Status ListInsert(SqList &L,int i,ElemType e){
	//�ڵ�i��Ԫ��֮������µ�Ԫ��
	if(i<1||i>L.length+1)	ErrorMessage("iֵ���Ϸ�");
	//�����������
	if(L.length>=L.listSize)	incrementList(L);
	//��i��Ԫ�ص�ַ 
	ElemType* q=&(L.elem[i-1]);
	//��βԪ�ص�ַ 
	ElemType* s=L.elem+L.length-1;
	//�ƶ�Ԫ��
	for(;s>=q;s--)	*s=*(s-1); 
	*q=e;
	L.length+=1;
	return OK;
}

//11.ɾ��Ԫ�ز���
Status ListDelete(SqList &L,int i, ElemType &e){
	if(i<1 || i>L.length+1)	ErrorMessage("iֵ���Ϸ�");
	ElemType* p=&(L.elem[i-1]);//Ҫɾ��Ԫ�ص�λ��
	e=*p;//��ɾ��Ԫ�ظ�ֵ��e
	//��βԪ��λ��
	ElemType* q=L.elem+L.length-1;
	//Ԫ������
	for(++p;p<=q;++p)	*(p-1)=*p;
	L.length-=1; 
	return OK;
} 

//12.�������L��ÿ������Ԫ�� 
void ListTraverse(SqList L){
	for(int i=0;i<L.length;i++){
		printf("%d ",L.elem[i]); 
	}
}
