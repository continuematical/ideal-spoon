//函数指针
//回调函数
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
	printf("请输入a，b的值：");
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
		printf("请输入:");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			ret = CAL(ADD);
			printf("答案是%d\n", ret);
			break;
		case 2:
			ret = CAL(MUL);
			printf("答案是%d\n", ret);
			break;
		case 3:
			ret = CAL(SUB);
			printf("答案是%d\n", ret);
			break;
		case 4:
			ret = CAL(DIV);
			printf("答案是%d\n", ret);
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请重新选择");
		}
	} while (1);
	return 0;
}