#include<stdio.h>
#include<stdlib.h>
int main()
{
	int row, col;
	printf("请输入矩阵的行和列：\n");
	scanf_s("%d %d", &row, &col);
	int**arr = (int**)malloc(sizeof(int) * row);
	for (int i = 0; i < row; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * col);
		for (int j = 0; j < col; j++)
		{
			scanf_s("%d", *arr[j]);
		}
	}
	
	return 0;
}