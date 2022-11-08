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

//���ַ������Ƶ�ǰһ���ַ�������
char* my_strcat(char* str1, char* str2)
{
	char* tmp = str1;
	while (*str1)
		str1++;
	while (*str1++ = *str2++);
	return tmp;
}

//���ڶ����ַ���ǰnλ���Ƶ�str1����
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

//�Ƚ������ַ���
int my_strcmp(char* str1, char* str2)
{
	while (*str1 == *str2)
	{
		if (str1 == '\0')
			break;//���
		str1++;
		str2++;
	}
	return (unsigned char)*str1 - (unsigned char)*str2;
}

//�Ƚ������ַ�����ǰn���ַ��Ƿ����
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
	if (!n)	return 0;//���
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