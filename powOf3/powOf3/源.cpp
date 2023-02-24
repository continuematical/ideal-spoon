#include<stdio.h>
void powOf3(int n)
{
	if ((n % 3 == 0) || (n == 1)) {
		if (n == 1)
		{
			printf("正确");
			return;
		}
		powOf3(n / 3);
	}
	else {
		printf("错误\n");
	}
}
int main()
{
	int n;
	printf("请输入一个整数：\n");
	scanf_s("%d", &n);
	powOf3(n);
}