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
   InitList(La);
    
   //3.�����Ա�����Ϊ��  

   //4.�ж�La�Ƿ�Ϊ��

   //5.������Ա�ĳ���
   printf("���Ա�ĳ���Ϊ��");
   printf("%d\n",ListLength(La)); 
   
   printf("*******Input A (����������3��Ԫ��)*******\n");
   InputElement(La);
   
   //6.��e����L�е�i��Ԫ�ص�ֵ 
   printf("*********��e����L�е�i��Ԫ�ص�ֵ*********\n");
   printf("������iֵ��");
   scanf("%d",&i);
   GetElem(La,i,e);
   printf("��%d��Ԫ�ص�ֵΪ��%d\n",i,e);

   //7.����e��λ�� 
   printf("**********����e��λ��**********"); 
   printf("������Ԫ��e��");
   scanf("%d",&e);
   printf("e��λ���ǣ�%d\n",LocateElem(La,e)); 

   //8.��ǰ�� 

   //9.�Һ�� 

   //10.���� 

   //11.ɾ��Ԫ��e 

   //12.���� 
   printf("*****************�������Ա�*****************\n");
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
