#include<stdio.h>
#include<math.h>
int main()
{
	/*double a;*///.5/0.500000  12./12.000000
	/*scanf_s("%lf", &a);
	printf("%lf\n", a);*/
	//计算三种浮点型的长度
	/*printf("%u\n", sizeof(float));
	printf("%u\n", sizeof(double));
	printf("%u\n", sizeof(long double));*/

	//输入一个实数为面积，求面积为该实数的正方形的边长
	/*printf("请输入一个实数：");
	double s = 0;
	scanf_s("%lf",&s);
	printf("%.2f", sqrt(s));*/

	//循环的控制
	//float x;
	//for (x = 0.0; x <= 1; x += 0.01)
	//{
	//	printf("%f\n", x);//0.999999计算机不能保证内部转化为二进制的浮点数每一位都不丢失，因此将1000份的误差积累在x中
	//}

	//不积累误差
	float x;
	for (float i = 0; i <= 100; i++)
	{
		x = i / 100;
		printf("%f\n", x);
	}
	//循环判断变量基准应该使用整型而不要用浮点数
	return 0;
}