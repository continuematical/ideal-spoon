//�жϻ������ֽ���
#include<stdio.h>
int main()
{
	int a = 1;
	char* p = (char*) & a;
	if (*p==0)
	{
		printf("���");
	}
	else {
		printf("С��");
	}
	return 0;
}