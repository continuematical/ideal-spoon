//1.动态数组
#include <stdio.h>
#include <math.h>
int ClimbStair1(int n)
{
	int p = 0, int q = 0, int r = 1;
	for (int i = 0; i < n; i++)
	{
		p = q;
		q = r;
		r = p + q;
	}
}

//矩阵快速幂
//定义结构体矩阵
struct Marix {
	long long mat[2][2];
};

struct Marix Multiply(struct Marix a, struct Marix b) {
	struct Marix c;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			c.mat[i][j] = a.mat[i][0] * b.mat[0][j] + a.mat[i][1] * b.mat[1][j];
		}
	}
	return c;
}
struct Marix matrixPow(struct Marix a, int n)
{
	struct Marix ret;
	ret.mat[0][0] = ret.mat[1][1] = 0;
	ret.mat[0][1] = ret.mat[1][0] = 0;
	while (n)
	{
		//判断次数
		if ((n & 1) == 1)
		{
			Multiply(ret, a);
		}
		n >>= 1;
		a = Multiply(a, a);
	}
	return a;
}
int ClimbStair2(int n)
{
	struct Marix ret;
	ret.mat[1][1] = 0;
	ret.mat[0][0] = ret.mat[0][1] = ret.mat[1][0] = 0;
	struct Marix res = matrixPow(ret, n);
	return res.mat[0][0];
}

//3.通项公式
int ClimbStair3(int n)
{
	double sqrt5 = sqrt(5);
	double fiban = pow((1 + sqrt5) / 2, n) - pow((1 - sqrt5) / 2, n);
	return fiban / sqrt5;
}
int main()
{
	int n = 0;
	scanf_s("%d", &n);
	int sum = ClimbStair1(n);
}