#include<stdio.h>
void powOf3(int n)
{
	if ((n % 3 == 0) || (n == 1)) {
		if (n == 1)
		{
			printf("��ȷ");
			return;
		}
		powOf3(n / 3);
	}
	else {
		printf("����\n");
	}
}
int main()
{
	int n;
	printf("������һ��������\n");
	scanf_s("%d", &n);
	powOf3(n);
}