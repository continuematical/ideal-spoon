//判断机器的字节序
#include<stdio.h>
int main()
{
	int a = 1;
	char* p = (char*) & a;
	if (*p==0)
	{
		printf("大端");
	}
	else {
		printf("小端");
	}
	return 0;
}