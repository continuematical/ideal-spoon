//编写rrotate(lrotate)函数返回无符号整数，返回无符号整数x右(左)移n位后的值

#include<stdio.h>
unsigned int rrotate(unsigned a,int n)
{
	return (a >>= n);
}
unsigned int rrotate(unsigned a, int n)
{
	return (a <<= n);
}

//将第pose位设置为1
unsigned int set(unsigned a, int pos)
{
	unsigned mask = 1u;
	a = a | (1u << pos);
	return a;
}
//将第pos位设置为0
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
//将第pos位到第pos+n-1位的二进制位设为0
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
//将第pos位到第pos+n-1位的二进制位设为1
unsigned reset_n(unsigned a, int pos, int n)
{
	unsigned mask = 1u;
	for (int i = 0; i < n; i++)
	{
		a = a | (1u << (pos + i - 1));
	}
	return a;
}
//pos开始后的n位后按位取反
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
	printf("请输入一个无符号整数,起始位数，终点位数：\n");
	scanf_s("%u %d %d", &a,&pos,&n);
	printf("%u", inverse_n(a,pos,n));
	return 0;
}
