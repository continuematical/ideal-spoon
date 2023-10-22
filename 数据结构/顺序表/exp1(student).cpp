/**********************************************************/
 /*           ���Ա�ľ�̬�洢�ṹ���Գ���                 */
 /**********************************************************/
#include "head.h"
#include "SqStaticListFunc.cpp" // �������Ա�ľ�̬�洢�ṹ
void InputElement(SqList &L); //���뼯��Ԫ�ص����Ա�L�� 
void print(ElemType &c); 

int main(){
   SqList La;
   ElemType e,preE,nextE; 
   int i; 
   
   //1.��ʼ�����Ա�La 
   if(InitList(La))	printf("��ʼ���ɹ�\n");
    
   //3.�����Ա�����Ϊ�� 
   if(clearList(La))	printf("���Ա�����Ϊ��\n"); 

   //4.�ж�La�Ƿ�Ϊ��
   if(ListEmpty(La))	printf("���Ա�Ϊ��\n");

   //5.������Ա�ĳ���
   printf("���Ա�ĳ���Ϊ��");
   printf("%d\n",ListLength(La)); 
   
   printf("\n*******Input A (����������3��Ԫ��)*******\n");
   InputElement(La);
   
   //6.��e����L�е�i��Ԫ�ص�ֵ 
   printf("\n*********��e����L�е�i��Ԫ�ص�ֵ*********\n");
   printf("������iֵ��");
   scanf("%d",&i);
   GetElem(La,i,e);
   printf("��%d��Ԫ�ص�ֵΪ��%d\n",i,e);

   //7.����e��λ�� 
   printf("\n**********����e��λ��**********\n"); 
   printf("������Ԫ��e��");
   scanf("%d",&e);
   printf("e��λ���ǣ�%d\n",LocateElem(La,e)); 

   //8.��ǰ�� 
   printf("\n**********Ѱ��e��ǰ��**********\n");
   printf("������Ԫ��e��");
   scanf("%d",&e); 
   if(PriorElem(La,e,preE)==OK)	printf("e��ǰ����%d\n",preE); 
   else	printf("eû��ǰ��\n");

   //9.�Һ�� 
   printf("\n**********Ѱ��e�ĺ��**********\n");
   printf("������Ԫ��e��");
   scanf("%d",&e); 
   if(NextElem(La,e,nextE)==OK)	printf("e�ĺ�̣�%d\n",nextE);
   else printf("eû�к��\n");

   //11.ɾ��Ԫ��e 
   printf("\n************ɾ��Ԫ��e**********\n");
   printf("������ɾ��Ԫ�صı�ţ�");
   scanf("%d",&i);
   if(ListDelete(La,i,e)==OK)	printf("��ɾ����Ԫ���ǣ�%d\n",e);

   //12.���� 
   printf("\n*****************�������Ա�*****************\n");
   printf("La = { "); // �������A
   ListTraverse(La);
   printf("}\n");
   //2.�������Ա� 
   DestroyList(La);

   return 0;
 }

void InputElement(SqList &L){
   int i, num, e;
   
   printf("�������ݸ��� num  = ");
   scanf("%d", &num);
   printf("��������� elem = \n");
   
   for(i = 0; i < num; i++){
	 scanf("%d", &e);
	 ListInsert(L, i+1, e); 
   }
}

void print(ElemType &c){
   printf("%d ",c);
}
