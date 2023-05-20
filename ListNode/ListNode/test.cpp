#include"标头.h"
int main()
{
	ListNode* phead = NULL;
	phead = ListNodeInit();
	ListNodePushBack(phead, 1);
	ListNodePushBack(phead, 2);
	ListNodePushBack(phead, 3);
	ListNodePushBack(phead, 4);

	ListPrint(phead);
	
	ListNodePopFront(phead);
	ListInsert(phead, 7);

	ListPrint(phead);

	ListDestroy(phead);
	phead = NULL;//清除指向哨兵位的指针
	//也可以传递二级指针，但是要保持函数接口的统一性
	return 0;
}