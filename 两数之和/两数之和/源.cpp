#include<stdio.h>
int* twoSum(int* num, int numsize, int target, int* returnSize)
{
	int x = 0, i = 0, j = 0;
	for (i = 0; i < numsize - 1; i++)
	{
		x = num[i];
		for (j= i+1; j < numsize - i; j++)
		{
			if (num[i] + num[j] == target)
			{
				int returnSize[2];
				returnSize[0] = i;
				returnSize[1] = j;
				return returnSize;
			}
		}
	}
	return NULL;
}

