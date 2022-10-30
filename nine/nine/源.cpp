#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 12

//计算字符串长度
int str_length(const char arr[])
{
	int i = 0;
	while (arr[i])
		i++;
	return i;
}

//返回字符c的下标
int str_char(const char s[])
{
	int i = 0;
	while (*s)
	{
		if (*s++ == 'c')
			return i;
		i++;
	}
	return -1;
}

//返回字符c的个数
int str_chnum(const char s[])
{
	int i = 0;
	while (*s)
	{
		if (*s++ == 'c')
			i++;
	}
	return i;
}

//字符串s显示n次
void put_stringn(const char s[],int n)
{
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		while (s[j])
			putchar(s[j++]);
		j = 0;
	}
}

//字符串的逆向输出
void put_stringr(const char s[])
{
	int len = strlen(s);
	char m[128];
	for (int i = 0; i < len; i++)
	{
		m[i] = s[len - i - 1];
		putchar(m[i]);
	}
}

//计算数字字符出现的次数
void str_dcount(const char s[],int cnt[])
{
	int i = 0;
	while (s[i])
	{
		if(s[i] >= '0' && s[i] <= '9')
			cnt[s[i] - 0]++;
		i++;
	}
}

//将字符串的英文字母转换为大写
void str_toupper(char s[])
{
	for (int i = 0; i < strlen(s); i++)
	{
		s[i] = toupper(s[i]);
	}
}
//将字符串的英文字母转换为小写
void str_tolower(char s[])
{
	for (int i = 0; i < strlen(s); i++)
	{
		s[i] = tolower(s[i]);
	}
}
//删除字符串中的数字
void del_digit(char s[])
{
	int i = 0;
	while (s[i]){
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else {
			putchar(s[i]);
			i++;
		}
	}
}

int main()
{
	//格式化显示字符串
	char a[] = "123456";
	printf("%s\n", a);//全部输出
	printf("%3s\n", a);//至少显示三位
	printf("%.3s\n", a);//最多显示三位
	printf("%8s\n", a);//右对齐
	printf("%-8s\n", a);//左对齐
	//字符串数组
	/*char str[][5] = { "abc","wetr","wer" };
	for (int i = 0; i < 3; i++)
	{
		printf("%s\n", str[i]);
	}

	char ab[N][128];
	for (int i = 0; i < N; i++)
	{
		scanf_s("%s", ab[i],128);
		if (strcmp(ab[i], "$$$$$") == 0)
			break;
	}
	for (int i = 0; i < N; i++)
	{
		if (strcmp(ab[i], "$$$$$") == 0)
			break;
		else
			printf("%s\n", ab[i]);
	}*/

	//显示字符串长度
	//char str[128];
	//printf("请输入字符串：");
	//scanf_s("%s\n", str,128);//scanf_s函数输入字符串时需要输入字符串长度的参数
	//printf("字符串%s的长度为%d", str, str_length(str));

	char s[128];
	int cnt[10] = { 0 };
	int n;
	printf("请输入字符串：");
	scanf_s("%s", s, 128);
	//scanf_s("%d", &n);
	del_digit(s);
	return 0;
}