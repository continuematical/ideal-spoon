#include <stdio.h>
#include <string.h>
//1,循环
char* string_rotate(char* string,int k)
{
	int n = strlen(string);
	for (int i = 0; i < k; i++)
	{
		char tmp = *string;
		for (int j = 0; j < n - 1; j++)
		{
			*(string + j) = *(string + j + 1);
		}
		*(string + n - 1) = tmp;
	}
	return string;
}
//2.三步反转法
char* reverse(char* str1, char* str2)
{
	char* left = str1;
	char* right = str2;
	while (left < right) {
		char tmp = *left;
		*left++ = *right;
		*right-- = tmp;
	}
	return str1;
}

int main()
{
	char string[10] = "ABCDEFG";
	int k;
	printf("请输入左旋转的位数：");
	scanf_s("%d", &k);
	int n = strlen(string);
	//string_rotate(string,k);
	reverse(string, string + k - 1);
	reverse(string + k, string + n - 1);
	reverse(string, string + n - 1);
	printf("%s\n", string);
	return 0;
}