#include<stdio.h>
int count_bits(unsigned x)
{
	int bits = 0;
	while (x)
	{
		if (x & 1u)  bits++;
		x >>= 1;
	}
	return bits;
}
int int_bits(void)
{
	return count_bits(~0u);
}

//显示数字i的后16位 
void print_nbits(unsigned x,int n)
{
	int i = int_bits();
	i = (i < n) ? (i - 1) : (n - 1);
	for (; i >= 0; i--)
	{
		putchar(((x >> i) & 1u) ? '1' : '0');
	}
}
//以十进制，八进制，十六进制显示数字
int main()
{
	unsigned i = 0;
	for (i = 1; i < 17; i++)
	{
		printf("%2d %2o %2x ", i,i,i);
		print_nbits(i, 16);
		printf("\n");
	}
	return 0;
}