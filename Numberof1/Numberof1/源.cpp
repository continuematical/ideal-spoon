#include<stdio.h>
int Numberof1(int a)
{
	int count = 0;
	while (a)
	{
		a = a & (a - 1);
		count++;
	}
	return count;
}
int main()
{
	int a;
	printf("输入一个数：\n");
	scanf_s("%d", &a);
	int num = Numberof1(a);
	printf("%d", num);
	return 0;
}