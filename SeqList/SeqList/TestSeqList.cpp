#include "SeqList.h"
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

//�ռ䲻���������¿ռ��������
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
	//�ռ��㹻��ֱ�Ӳ���
	ps->a[ps->size] = x;
	ps->size++;
}
//�ڴ��ͷ�
void SeqListDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = NULL;
}

//β��ɾ��һ������
void SeqListPopBack(SL* ps, SLDataType x)
{
	if (ps->size > 0)
	{
		ps->a[ps->size - 1] = NULL;
		ps->size--;//ֻд���г������׵���Խ�磬��������鲻����
	}
	assert(ps->size > 0);
	//���߶��ԣ�ʹ�ñ�����
}

//��ӡ����
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//ͷ������һ������
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
//ͷ��ɾ��һ������
void SeqListPopFront(SL* ps) {
	assert(ps->size > 0);
	int begin = 1;
	while (begin < ps->size) {
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}
	ps->size--;
}