#include<stdlib.h>
#include<stdio.h>
int main()
{
	int n, m;
	printf("������������\n");
	scanf_s("%d", &n);
	printf("���뱨����\n");
	scanf_s("%d", &m);
	int* arr = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}
	int count = 0;//��������
	int out = 0;//�˳���������
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