#include <stdio.h>
#include <stdlib.h>
int FriendNumber(int x)
{
	int sum = 0;
	while (x) {
		sum = sum + x % 10;
		x /= 10;
	}
	return sum;
}
int main()
{
	int n = 0;
	int arr2[37] = { 0 };
	scanf_s("%d", &n);
	int* arr1 = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr1[i]);
		int sum = FriendNumber(arr1[i]);
		arr2[sum]++;
	}
	for (int i = 0; i < 37; i++)
	{
		if (arr2[i] > 0)
		{
			printf("%d ", i);
		}
	}
	return 0;
}