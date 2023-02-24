#include"标头.h"

void TestSList1()
{
	SList* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);

	SListPrint(plist);

	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);
	SListPushFront(&plist, 6);

	SListPrint(plist);

	/*SList* pos = SListFind(plist, 6);
	SListEraceAfter(&plist, pos);*/

	SListPrint(plist);

	SListReverseK(plist, 2);

	SListReverse(plist);
	/*SList* pow = NULL;
	pow = SListFind(plist, 5);
	int i = 1;
	while (pow)
	{
		printf("第%d个 %p->%d\n", i++, pow,pow->data);
		pow = SListFind(pow->next, 5);
	}*/
}

void TestSList2()
{
	SList* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 9);
	//sll_insert(&plist,7);
	SListPrint(plist);
}

int main()
{
	TestSList2();
	return 0;
}