#include "SeqList.h"
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

//空间不够：开辟新空间或者扩容
void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("reallo fail");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

void SeqListPushBack(SL* ps,SLDataType x)
{
	SeqListCheckCapacity(ps);
	//空间足够，直接插入
	ps->a[ps->size] = x;
	ps->size++;
}
//内存释放
void SeqListDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = NULL;
}

//尾部删除一个数据
void SeqListPopBack(SL* ps, SLDataType x)
{
	if (ps->size > 0)
	{
		ps->a[ps->size - 1] = NULL;
		ps->size--;//只写这行程序容易导致越界，编译器检查不出来
	}
	assert(ps->size > 0);
	//或者断言，使用报错函数
}

//打印数组
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//头部插入一个数据
void SeqListPushFront(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;
}
//头部删除一个数据
void SeqListPopFront(SL* ps) {
	assert(ps->size > 0);
	int begin = 1;
	while (begin < ps->size) {
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}
	ps->size--;
}