#include<limits.h>
#include<stdio.h>
int main()
{
	/*printf("%d-%d\n",CHAR_MIN, CHAR_MAX);
	printf("%d-%d\n",0, UCHAR_MAX);
	printf("%d-%d\n", SCHAR_MIN, SCHAR_MAX);
	printf("%d-%d\n", INT_MIN, INT_MAX);
	printf("%u-%u\n", 0, UINT_MAX);
	printf("%ld-%ld\n", LONG_MIN, LONG_MAX);
	printf("%lu-%lu\n", 0, ULONG_MAX);
	printf("%u-%u\n", 0, USHRT_MAX);
	printf("%d-%d\n", SCHAR_MIN, SCHAR_MAX);*/

	//λ�Ǿ��д����ڴ�ռ�����л��������ݴ洢��λ����ȡ����ֵ��0������ֵ������ֵ��
	/*if (CHAR_MIN)
	{
		printf("���char�������з��ŵ�\n");
	}
	else {
		printf("���char�������޷��ŵ�\n");
	}
	printf("%d", CHAR_BIT);*/

	//sizeof���㣬����ֵΪsize_t
	printf("%zd\n", sizeof(int));
	printf("%zd\n", sizeof(short));
	printf("%zd\n", sizeof(long));

}