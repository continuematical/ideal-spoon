//�����ַ�����������
#include<stdio.h>
#include<string.h>
//��ȡ��$$$$$ʱֹͣ��ȡ����ʾ֮ǰ���ַ���
void put_stray(char s[][6], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		int j = 0;
		if (strcmp(s[i], "$$$$$") == 0) {
			break;
		}
		printf("s[%d]=\"", i);
		while (s[i][j])
		{
			putchar(s[i][j++]);
		}
		puts("\"");
	}
}
//�����ַ�������ʾ
void put_string_ref(char s[])
{
	int i = 0;
	while (s[i]) {
		putchar(s[i++]);
	}
	printf(":{");
	i = 0;
	while (s[i]) {
		putchar('\'');
		putchar(s[i++]);
		putchar('\'');
		printf(",");
	}
	printf("'\\0'");
	printf("}");
}
int main()
{
	char s[6] = "DOUBT";
	put_string_ref(s);
	return 0;
}