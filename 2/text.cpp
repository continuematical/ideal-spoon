#include "LinkList.cpp"

int main(){
	int length,i,result;
	ElemType e,pre_e,nex_e;
	LinkList head=newNode();
	
	printf("�������ʼ������ĳ��ȣ�");
	scanf("%d",&length); 
	InitList(head,length);
	
	printf("�����Ƿ�Ϊ�ձ�\n"); 
	printf("%d\n",ListEmpty(head));
	
//	printf("\n����Ԫ��\n");
//	printf("�������Ԫ�صı�ź�ֵ\n");
//	scanf("%d %d",&i,&e);
//	ListInsert(head,i,e);
//	
//	printf("\n��������Ԫ�ص�λ��");
//	printf("���������ݣ�");
//	scanf("%d",&e);
//	result=LocateElem(head,e);
//	if(result==ERROR)	printf("�����Ԫ�ز���������\n"); 
//	else	printf("%d",result);
//	
//	printf("\n��������\n");
//	ListTraverse(head);
//	
//	printf("\n������Ϊ��");
//	printf("%d",ListLength(head));
	
	result=PriorElem(head,10,pre_e);
	if(result==OK)	printf("%d",pre_e);
	else	printf("��Ԫ����ǰ��\n");
	
	DestroyList(head);
	return 0;
}
