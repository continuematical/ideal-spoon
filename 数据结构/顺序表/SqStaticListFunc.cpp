#include "head.h"
#include "ErrorMessage.cpp"

typedef struct{
	ElemType* elem;//存储元素的一维数组 
	int length;//线性表长度
	int listSize;//当前分配的线性表容量
	int incrementSize;//约定的增补空间 
}SqList; 

//增补空间
Status incrementList(SqList &L){
	//为顺序表增大元素空间
	ElemType a[L.listSize+L.incrementSize];
	//转移元素
	for(int i=0;i<L.length;i++){
		a[i]=L.elem[i];
	} 
	free(L.elem);
	L.elem=a;
	//增大容量 
	L.listSize+=L.incrementSize;
	return OK;
}

//1.初始化线性表 
Status InitList(SqList &L){
	L.elem=new ElemType[LIST_INIT_SIZE];
	L.listSize=LIST_INIT_SIZE;
	L.incrementSize=LISTINCREMENT;
	L.length=0;
	return OK;
} 

//2.销毁线性表
Status DestroyList(SqList L){
	delete[] L.elem;
	L.length=0;
	L.listSize=0;
	return OK;
} 

//3.清空线性表
Status clearList(SqList &L){
	for(int i=0;i<L.length;i++){
		L.elem[i]=0;
	}
	L.length=0;
	return OK;
}

//4.是否为空表 
int ListEmpty(SqList L){
	if(L.elem!=NULL){
		if(L.length==0)	return true;
		else return false;	
	} else{
		ErrorMessage("未初始化\n");
	}
} 

//5.L中元素个数 
int ListLength(SqList L){
	if(L.elem!=NULL){
		return L.length;	
	}else{
		ErrorMessage("未初始化\n");
	}
} 

//6.用e返回L中第i个元素的值
Status GetElem(SqList L, int i, ElemType &e){
	if(i<1||i>L.length){
		ErrorMessage("i值不合法");
		return ERROR;
	}
	e=L.elem[i-1];
	return OK;
} 

//7.查找元素操作
int LocateElem(SqList L, ElemType e){
	int i=1;//起始位置
	ElemType* p=L.elem;//数组起始地址
	while(i<=L.length && *p++!=e)	i++;
	if(i<=L.length)	return i;
	else	return 0;//如果没有该元素，则返回 0
}

//8.查找元素的前驱 
Status PriorElem(SqList L, ElemType cur_e, ElemType& pre_e){
	if(L.elem==NULL || LocateElem(L,cur_e)==1)	return ERROR; 
	int i=LocateElem(L,cur_e);
	pre_e=L.elem[i-2];
	return OK;
}

//9.查找元素的后继 
Status NextElem(SqList L, ElemType cur_e, ElemType& next_e){
	if(L.elem==NULL || LocateElem(L,cur_e)==L.length)	return ERROR;
	int i=LocateElem(L,cur_e);
	next_e=L.elem[i];
	return OK;
}

//10.插入元素操作
Status ListInsert(SqList &L,int i,ElemType e){
	//在第i个元素之后插入新的元素
	if(i<1||i>L.length+1)	ErrorMessage("i值不合法");
	//如果容量不够
	if(L.length>=L.listSize)	incrementList(L);
	//第i个元素地址 
	ElemType* q=&(L.elem[i-1]);
	//表尾元素地址 
	ElemType* s=L.elem+L.length-1;
	//移动元素
	for(;s>=q;s--)	*s=*(s-1); 
	*q=e;
	L.length+=1;
	return OK;
}

//11.删除元素操作
Status ListDelete(SqList &L,int i, ElemType &e){
	if(i<1 || i>L.length+1)	ErrorMessage("i值不合法");
	ElemType* p=&(L.elem[i-1]);//要删除元素的位置
	e=*p;//被删除元素赋值给e
	//表尾元素位置
	ElemType* q=L.elem+L.length-1;
	//元素左移
	for(++p;p<=q;++p)	*(p-1)=*p;
	L.length-=1; 
	return OK;
} 

//12.依次输出L中每个数据元素 
void ListTraverse(SqList L){
	for(int i=0;i<L.length;i++){
		printf("%d ",L.elem[i]); 
	}
}
