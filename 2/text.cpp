#include "LinkList.cpp"

int main(){
	int length,i,result;
	ElemType e,pre_e,nex_e;
	LinkList head=newNode();
	
	printf("请输入初始化链表的长度：");
	scanf("%d",&length); 
	InitList(head,length);
	
	printf("链表是否为空表\n"); 
	printf("%d\n",ListEmpty(head));
	
//	printf("\n插入元素\n");
//	printf("输入插入元素的编号和值\n");
//	scanf("%d %d",&i,&e);
//	ListInsert(head,i,e);
//	
//	printf("\n返回数据元素的位置");
//	printf("请输入数据：");
//	scanf("%d",&e);
//	result=LocateElem(head,e);
//	if(result==ERROR)	printf("输入的元素不在链表中\n"); 
//	else	printf("%d",result);
//	
//	printf("\n遍历链表\n");
//	ListTraverse(head);
//	
//	printf("\n链表长度为：");
//	printf("%d",ListLength(head));
	
	result=PriorElem(head,10,pre_e);
	if(result==OK)	printf("%d",pre_e);
	else	printf("该元素无前驱\n");
	
	DestroyList(head);
	return 0;
}
