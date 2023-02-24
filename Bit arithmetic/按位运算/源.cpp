#include <stdio.h>
//计算接收到的无符号整型有多少个二进制位的1，并返回其个数
int count_int(unsigned x)
{
	int bits = 0;
	while (x)
	{
		if (x && 1u) bits++;
		x >>= 1;
	}
}

//返回unsigned型的位数
int int_bits()
{
	return count_int(~ 0U);
}

//输出指定数的二进制位的内容
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
	printf("请输入两个非负整数：");
	scanf_s("%u %u", &a, &b);
	print(a);
	return 0;
}