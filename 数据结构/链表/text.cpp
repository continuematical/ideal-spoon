#include "LinkList.cpp"

int main(){
	int lengthA, lengthB;
	LinkList La=newNode();
	LinkList Lb=newNode(); 
	LinkList Lc=newNode();
	
	printf("����������La�ĳ��ȣ�");
	scanf("%d",&lengthA); 
	InitList(La,lengthA);
	
	printf("����������Lb�ĳ��ȣ�");
	scanf("%d",&lengthB);
	InitList(Lb,lengthB);
	
	printf("La��"); 
	ListTraverse(La);
	
	printf("Lb��"); 
	ListTraverse(Lb);
	
	clearList(Lc); 
	printf("La��Lb�Ľ���Ϊ��\n");
	jiao(La,Lb,Lc);
	ListTraverse(Lc);
	
	clearList(Lc); 
	printf("La��Lb�Ĳ���Ϊ��\n");
	bing(La,Lb,Lc);
	ListTraverse(Lc);
	
	clearList(Lc);
	ListTraverse(Lc);
	printf("La-Lb��\n");
	cha(La, Lb, Lc);
	ListTraverse(Lc);
	
	clearList(Lc);
	printf("Lb-La��\n");
	cha(Lb, La, Lc);
	ListTraverse(Lc);
	
	return 0;
}
