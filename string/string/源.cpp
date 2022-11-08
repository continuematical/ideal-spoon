#include <stdio.h>
#include <assert.h>
char* my_strcpy(char* str1,const char* str2)
{
	char* tmp = str1;
	while (*str1++ = *str2++);
	return tmp;
}

char* my_strncpy(char* str1, const char* str2, int n)
{
	char* tmp = str1;
	while (n)
	{
		if (!(*str1++ = *str2++))
		{
			break;
		}
		n--;
	}
	while (n--)
	{
		*str1 = '\0';
	}
	return tmp;
}

//将字符串复制到前一个字符串后面
char* my_strcat(char* str1, char* str2)
{
	char* tmp = str1;
	while (*str1)
		str1++;
	while (*str1++ = *str2++);
	return tmp;
}

//将第二个字符串前n位复制到str1后面
char* my_strncat(char* str1, char* str2, int n)
{
	char* tmp = str1;
	while (*str1)
		str1++;
	while (n--)
	{
		/*if (n == 1)
		{
			*str1 = '\0';
		}
		*str1++ = *str2++;*/
		if (!(*str1++ = *str2++))
			break;
	}
	*str1 = '\0';
	return tmp;
}

//比较两个字符串
int my_strcmp(char* str1, char* str2)
{
	while (*str1 == *str2)
	{
		if (str1 == '\0')
			break;//相等
		str1++;
		str2++;
	}
	return (unsigned char)*str1 - (unsigned char)*str2;
}

//比较两个字符串的前n个字符是否相等
int my_strcmp(char* str1, char* str2, int n)
{
	assert(n != 0);
	while (n && *str1 && *str2)
	{
		if (*str1 != *str2)
			break;
		str1++;
		str2++;
		n--;
	}
	if (!n)	return 0;//相等
	if (*str1) return 1;//str1>str2
	return -1;
}

int main()
{
	char str1[30] = "nihao ";
	char str2[20] = "hello world";
	char* tmp = my_strncat(str1, str2, 4);
	printf("%s", tmp);
	return 0;
}