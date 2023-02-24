#include<stdio.h>
#include<math.h>
int main()
{
	char A[8];
	char B[8];
	double count = 0;
	int num = 0;
	scanf_s("%s", &A, 8);
	scanf_s("%s", &B, 8);

	for (int i = 6; i >= 0; i--)
	{
		if (A[i] == '0' && B[i] == '1')
			break;
		else if (A[i] == '0')
			count++;
		else if (B[i] == '1')
			count++;
	}
	num = (int)pow(2.0, 7-count);
	if (count == 0)
		num = 0;
	printf("%d", num);
	return 0;
}