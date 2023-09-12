#include "head.h"
#include "ErrorMessage.cpp"

typedef struct{
	ElemType* elem;//存储元素的一维数组 
	int length;//线性表长度
	int listSize;//当前分配的线性表容量
	int incrementSize;//约定的增补空间 
}SqList; 

//增补空间
void incrementList(SqList &L){
	//为顺序表增大元素空间
	ElemType a[L.listSize+L.incrementSize];
	//转移元素
	for(int i=0;i<L.length;i++){
		a[i]=L.elem[i];
	} 
	free(L.elem);
	L.elem=a;
	L.listSize+=L.incrementSize;
}

//1.初始化线性表 
void InitList(SqList &L){
	L.elem=new ElemType[LIST_INIT_SIZE];
	L.listSize=LIST_INIT_SIZE;
	L.incrementSize=LISTINCREMENT;
	L.length=0;
}

//2.销毁线性表
void DestroyList(SqList L){
	free(L.elem);
} 

//4.是否为空表 
int ListEmpty(SqList L){
	if(L.length==0)	return true;
	else return false;
} 

//5.L中元素个数 
int ListLength(SqList L){
	return L.length;
} 

//6.用e返回L中第i个元素的值
void GetElem(SqList L, int i, ElemType &e){
	if(i<1||i>L.length){
		ErrorMessage("i值不合法");
		return;
	}
	e=L.elem[i-1];
} 

//7.查找元素操作
int LocateElem(SqList L, ElemType e){
	int i=1;//起始位置
	ElemType* p=L.elem;//数组起始地址
	while(i<=L.length && *p++!=e)	i++;
	if(i<=L.length)	return i;
	else	return 0;//如果没有该元素，则返回 0
}

//10.插入元素操作
void ListInsert(SqList &L,int i,ElemType e){
	//在第i个元素之后插入新的元素
	if(i<1||i>L.length+1)	ErrorMessage("i值不合法");
	//如果线性表元素大于线性表容量 
	if(L.length>=L.listSize)	incrementList(L); 
	ElemType* p=&(L.elem[i-1]);
	//表尾元素位置
	ElemType* q=L.elem+L.length-1;
	//元素右移
	for(;q>=p;q--)	*q=*(q-1);
	*p=e;
	L.length+=1;
}

//11.删除元素操作
void ListDelete(SqList &L,int i, ElemType &e){
	if(i<1 || i>L.length+1)	ErrorMessage("i值不合法");
	ElemType* p=&(L.elem[i-1]);//要删除元素的位置
	e=*p;//被删除元素赋值给e
	//表尾元素位置
	ElemType* q=L.elem+L.length-1;
	//元素左移
	for(++p;p<=q;++p)	*(p-1)=*p;
	L.length-=1; 
} 

//12.依次输出L中每个数据元素 
void ListTraverse(SqList L){
	for(int i=0;i<L.length;i++){
		printf("%d ",L.elem[i]); 
	}
}
