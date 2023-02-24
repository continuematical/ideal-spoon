#include<stdio.h>
void bubble_sort(int arr[],int len)
{
	int i = 0;
	for (i = 0; i < len - 1; i++)
	{
		int j = 0;
		for (j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main()
{
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
}