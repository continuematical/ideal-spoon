/**********************************************************/
 /*           线性表的静态存储结构测试程序                 */
 /**********************************************************/
#include "head.h"
#include "SqStaticListFunc.cpp" // 采用线性表的静态存储结构
void InputElement(SqList &L); //输入集合元素到线性表L中 
void print(ElemType &c); 

int main(){
   SqList La;
   ElemType e,preE,nextE; 
   int i; 
   
   //1.初始化线性表La 
   InitList(La);
    
   //3.将线性表重置为空  

   //4.判断La是否为空

   //5.输出线性表的长度
   printf("线性表的长度为：");
   printf("%d\n",ListLength(La)); 
   
   printf("*******Input A (请输入至少3个元素)*******\n");
   InputElement(La);
   
   //6.用e返回L中第i个元素的值 
   printf("*********用e返回L中第i个元素的值*********\n");
   printf("请输入i值：");
   scanf("%d",&i);
   GetElem(La,i,e);
   printf("第%d个元素的值为：%d\n",i,e);

   //7.返回e的位置 
   printf("**********返回e的位置**********"); 
   printf("请输入元素e：");
   scanf("%d",&e);
   printf("e的位置是：%d\n",LocateElem(La,e)); 

   //8.找前驱 

   //9.找后继 

   //10.插入 

   //11.删除元素e 

   //12.遍历 
   printf("*****************遍历线性表*****************\n");
   printf("La = { "); // 输出集合A
   ListTraverse(La);
   printf("}\n");
   //2.销毁线性表 
   DestroyList(La);

   return 0;
 }

void InputElement(SqList &L){
   int i, num, e;
   
   printf("插入数据个数 num  = ");
   scanf("%d", &num);
   printf("输入的数据 elem = \n");
   
   for(i = 0; i < num; i++){
	 scanf("%d", &e);
	 ListInsert(L, i+1, e); 
   }
}


void print(ElemType &c){
   printf("%d ",c);
}
