#include"��ͷ.h"
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
	phead = NULL;//���ָ���ڱ�λ��ָ��
	//Ҳ���Դ��ݶ���ָ�룬����Ҫ���ֺ����ӿڵ�ͳһ��
	return 0;
}