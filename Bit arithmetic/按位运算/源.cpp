#include <stdio.h>
//������յ����޷��������ж��ٸ�������λ��1�������������
int count_int(unsigned x)
{
	int bits = 0;
	while (x)
	{
		if (x && 1u) bits++;
		x >>= 1;
	}
}

//����unsigned�͵�λ��
int int_bits()
{
	return count_int(~ 0U);
}

//���ָ�����Ķ�����λ������
void print(unsigned int a)
{
	for (int i = int_bits() - 1; i >= 0; i--)
	{
		printf("%c", ((a >> i) & 1U) ? '1' : '0');
	}
}

int main()
{
	unsigned a, b;
	printf("�����������Ǹ�������");
	scanf_s("%u %u", &a, &b);
	print(a);
	return 0;
}