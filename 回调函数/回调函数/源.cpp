//����ָ��
//�ص�����
#include<stdio.h>
int ADD(int a, int b)
{
	return a + b;
}
int MUL(int a, int b)
{
	return a * b;
}
int SUB(int a, int b)
{
	return a - b;
}
int DIV(int a, int b)
{
	return a / b;
}
int CAL(int (*pf) (int,int))
{
	int a, b;
	printf("������a��b��ֵ��");
	scanf_s("%d %d", &a,&b);
	return pf(a, b);
}
void menu()
{
	printf("*************************\n");
	printf("*****  1.ADD 2.MUL  *****\n");
	printf("*****  3.SUB 4.DIV  *****\n");
	printf("*****     0.exit    *****\n");
	printf("*************************\n");
}
int main()
{
	int input = 0;
	do
	{
		int ret = 0;
		menu();
		printf("������:");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			ret = CAL(ADD);
			printf("����%d\n", ret);
			break;
		case 2:
			ret = CAL(MUL);
			printf("����%d\n", ret);
			break;
		case 3:
			ret = CAL(SUB);
			printf("����%d\n", ret);
			break;
		case 4:
			ret = CAL(DIV);
			printf("����%d\n", ret);
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("������ѡ��");
		}
	} while (1);
	return 0;
}