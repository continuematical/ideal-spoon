#include<stdio.h>
#include<stdlib.h>
void print(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int compar(const void *a,const void *b)//void*��ʾԪ�������Ƿ���
{
	return *(int*)a - *(int*)b;//������a��bǿ��ת��Ϊint*����
}
int main()
{
	int arr[10] = { 23,67,89,27,0,24,85,14,50,54 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("��ǰ���飺\n");
	print(arr, len);
	qsort(arr, len, sizeof(int), compar);
	//��һ������ĵ�ַ
	//����Ԫ�ظ���
	//һ��Ԫ�صĴ�С����λ���ֽ�
	//�Ƚ�����Ԫ�صĺ���
	printf("���к����飺\n");
	print(arr, len);
	return 0;
}