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
   if(InitList(La))	printf("初始化成功\n");
    
   //3.将线性表重置为空 
   if(clearList(La))	printf("线性表重置为空\n"); 

   //4.判断La是否为空
   if(ListEmpty(La))	printf("线性表为空\n");

   //5.输出线性表的长度
   printf("线性表的长度为：");
   printf("%d\n",ListLength(La)); 
   
   printf("\n*******Input A (请输入至少3个元素)*******\n");
   InputElement(La);
   
   //6.用e返回L中第i个元素的值 
   printf("\n*********用e返回L中第i个元素的值*********\n");
   printf("请输入i值：");
   scanf("%d",&i);
   GetElem(La,i,e);
   printf("第%d个元素的值为：%d\n",i,e);

   //7.返回e的位置 
   printf("\n**********返回e的位置**********\n"); 
   printf("请输入元素e：");
   scanf("%d",&e);
   printf("e的位置是：%d\n",LocateElem(La,e)); 

   //8.找前驱 
   printf("\n**********寻找e的前驱**********\n");
   printf("请输入元素e：");
   scanf("%d",&e); 
   if(PriorElem(La,e,preE)==OK)	printf("e的前驱：%d\n",preE); 
   else	printf("e没有前驱\n");

   //9.找后继 
   printf("\n**********寻找e的后继**********\n");
   printf("请输入元素e：");
   scanf("%d",&e); 
   if(NextElem(La,e,nextE)==OK)	printf("e的后继：%d\n",nextE);
   else printf("e没有后继\n");

   //11.删除元素e 
   printf("\n************删除元素e**********\n");
   printf("请输入删除元素的编号：");
   scanf("%d",&i);
   if(ListDelete(La,i,e)==OK)	printf("被删除的元素是：%d\n",e);

   //12.遍历 
   printf("\n*****************遍历线性表*****************\n");
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
