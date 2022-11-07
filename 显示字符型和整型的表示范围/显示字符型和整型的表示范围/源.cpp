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

	//位是具有大量内存空间的运行环境的数据存储单位，可取两种值，0和其他值（设置值）
	/*if (CHAR_MIN)
	{
		printf("这个char类型是有符号的\n");
	}
	else {
		printf("这个char类型是无符号的\n");
	}
	printf("%d", CHAR_BIT);*/

	//sizeof运算，返回值为size_t
	printf("%zd\n", sizeof(int));
	printf("%zd\n", sizeof(short));
	printf("%zd\n", sizeof(long));

}