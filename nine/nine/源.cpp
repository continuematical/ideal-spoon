#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 12

//�����ַ�������
int str_length(const char arr[])
{
	int i = 0;
	while (arr[i])
		i++;
	return i;
}

//�����ַ�c���±�
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

//�����ַ�c�ĸ���
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

//�ַ���s��ʾn��
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

//�ַ������������
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

//���������ַ����ֵĴ���
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

//���ַ�����Ӣ����ĸת��Ϊ��д
void str_toupper(char s[])
{
	for (int i = 0; i < strlen(s); i++)
	{
		s[i] = toupper(s[i]);
	}
}
//���ַ�����Ӣ����ĸת��ΪСд
void str_tolower(char s[])
{
	for (int i = 0; i < strlen(s); i++)
	{
		s[i] = tolower(s[i]);
	}
}
//ɾ���ַ����е�����
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
	//��ʽ����ʾ�ַ���
	char a[] = "123456";
	printf("%s\n", a);//ȫ�����
	printf("%3s\n", a);//������ʾ��λ
	printf("%.3s\n", a);//�����ʾ��λ
	printf("%8s\n", a);//�Ҷ���
	printf("%-8s\n", a);//�����
	//�ַ�������
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

	//��ʾ�ַ�������
	//char str[128];
	//printf("�������ַ�����");
	//scanf_s("%s\n", str,128);//scanf_s���������ַ���ʱ��Ҫ�����ַ������ȵĲ���
	//printf("�ַ���%s�ĳ���Ϊ%d", str, str_length(str));

	char s[128];
	int cnt[10] = { 0 };
	int n;
	printf("�������ַ�����");
	scanf_s("%s", s, 128);
	//scanf_s("%d", &n);
	del_digit(s);
	return 0;
}