#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	printf("������Ҫͳ��Ԫ���ĸ�����\n");
	scanf_s("%d", &n);
	getchar();//���ջس�����
	for (int i = 0; i < n; i++)
	{
		char a[100];
		int arr[5] = { 0 };
		printf("�������ַ�����");
		gets_s(a);
		int len = strlen(a);
		int j = 0;
		for (j = 0; j < len; j++)
		{
			switch (a[j])
			{
			case 'a':
				arr[0]++;
				break;
			case 'e':
				arr[1]++;
				break;
			case 'i':
				arr[2]++;
				break;
			case 'o':
				arr[3]++;
				break;
			case 'u':
				arr[4]++;
				break;
			default:
				break;
			}
		}
		for (int z = 0; z < 5; z++)
		{
			printf("%d\n", arr[z]);
		}
		if (i != n-1)
		{
			printf("\n");
		}
	}
	return 0;
}