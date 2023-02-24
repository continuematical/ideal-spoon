#include<stdlib.h>
#include<stdio.h>
int main()
{
	int n, m;
	printf("输入总人数：\n");
	scanf_s("%d", &n);
	printf("输入报数：\n");
	scanf_s("%d", &m);
	int* arr = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}
	int count = 0;//报数计数
	int out = 0;//退出人数计数
	int i;
	for (i = 0; i < n; i++)
	{
		if (arr[i] != 0)
		{
			count++;
			if (out == n - 1)
			{
				break;
			}
			if (count == m) {
				count = 0;
				out++;
				arr[i] = 0;
			}
			if (i = n - 1)
			{
				i = -1;
			}
		}
	}
	printf("%d", i);
	return 0;
}