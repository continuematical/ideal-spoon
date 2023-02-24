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
int compar(const void *a,const void *b)//void*表示元素类型是泛型
{
	return *(int*)a - *(int*)b;//将泛型a，b强制转化为int*类型
}
int main()
{
	int arr[10] = { 23,67,89,27,0,24,85,14,50,54 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("先前数组：\n");
	print(arr, len);
	qsort(arr, len, sizeof(int), compar);
	//第一个对象的地址
	//数组元素个数
	//一个元素的大小，单位是字节
	//比较两个元素的函数
	printf("排列后数组：\n");
	print(arr, len);
	return 0;
}