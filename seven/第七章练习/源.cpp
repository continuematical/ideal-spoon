//��дrrotate(lrotate)���������޷��������������޷�������x��(��)��nλ���ֵ

#include<stdio.h>
unsigned int rrotate(unsigned a,int n)
{
	return (a >>= n);
}
unsigned int rrotate(unsigned a, int n)
{
	return (a <<= n);
}

//����poseλ����Ϊ1
unsigned int set(unsigned a, int pos)
{
	unsigned mask = 1u;
	a = a | (1u << pos);
	return a;
}
//����posλ����Ϊ0
unsigned int reset(unsigned a, int pos)
{
	unsigned mask = 1u;
	if (a & (1u << pos))
	{
		return (a ^ (1u << pos));
	}else{
		return a;
	}
}
//����posλ����pos+n-1λ�Ķ�����λ��Ϊ0
unsigned set_n(unsigned a, int pos, int n)
{
	unsigned mask = 1u;
	for (int i = 0; i < n; i++)
	{
		if (a & (1u << (pos+i-1)))
			a=a^(1u<<(pos+i-1));
	}
	return a;
}
//����posλ����pos+n-1λ�Ķ�����λ��Ϊ1
unsigned reset_n(unsigned a, int pos, int n)
{
	unsigned mask = 1u;
	for (int i = 0; i < n; i++)
	{
		a = a | (1u << (pos + i - 1));
	}
	return a;
}
//pos��ʼ���nλ��λȡ��
unsigned inverse_n(unsigned a, int pos, int n)
{
	unsigned mask = 1u;
	for (int i = 0; i < n; i++)
	{
		a = a ^ (1u << (pos + i - 1));
	}
	return a;
}
int main()
{
	unsigned a;
	int n,pos;
	printf("������һ���޷�������,��ʼλ�����յ�λ����\n");
	scanf_s("%u %d %d", &a,&pos,&n);
	printf("%u", inverse_n(a,pos,n));
	return 0;
}
