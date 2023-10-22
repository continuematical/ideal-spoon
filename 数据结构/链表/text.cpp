#include "LinkList.cpp"

int main(){
	int lengthA, lengthB;
	LinkList La=newNode();
	LinkList Lb=newNode(); 
	LinkList Lc=newNode();
	
	printf("请输入链表La的长度：");
	scanf("%d",&lengthA); 
	InitList(La,lengthA);
	
	printf("请输入链表Lb的长度：");
	scanf("%d",&lengthB);
	InitList(Lb,lengthB);
	
	printf("La："); 
	ListTraverse(La);
	
	printf("Lb："); 
	ListTraverse(Lb);
	
	clearList(Lc); 
	printf("La和Lb的交集为：\n");
	jiao(La,Lb,Lc);
	ListTraverse(Lc);
	
	clearList(Lc); 
	printf("La和Lb的并集为：\n");
	bing(La,Lb,Lc);
	ListTraverse(Lc);
	
	clearList(Lc);
	ListTraverse(Lc);
	printf("La-Lb：\n");
	cha(La, Lb, Lc);
	ListTraverse(Lc);
	
	clearList(Lc);
	printf("Lb-La：\n");
	cha(Lb, La, Lc);
	ListTraverse(Lc);
	
	return 0;
}
