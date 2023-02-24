#include<stdio.h>
int length(char(*p[]))
{
	int i = 0;
	while (*p)
	{
		printf("%s\n", *p);
		p++;
		i++;
	}
	return i;
}

int main()
{
	char arr[][100] = { "123","456","789" };
	char(*p[3]) = { arr[0],arr[1],arr[2] };
	int len = length(p);
	return 0;
}