#include<stdio.h>
#include<math.h>
int main()
{
	/*double a;*///.5/0.500000  12./12.000000
	/*scanf_s("%lf", &a);
	printf("%lf\n", a);*/
	//�������ָ����͵ĳ���
	/*printf("%u\n", sizeof(float));
	printf("%u\n", sizeof(double));
	printf("%u\n", sizeof(long double));*/

	//����һ��ʵ��Ϊ����������Ϊ��ʵ���������εı߳�
	/*printf("������һ��ʵ����");
	double s = 0;
	scanf_s("%lf",&s);
	printf("%.2f", sqrt(s));*/

	//ѭ���Ŀ���
	//float x;
	//for (x = 0.0; x <= 1; x += 0.01)
	//{
	//	printf("%f\n", x);//0.999999��������ܱ�֤�ڲ�ת��Ϊ�����Ƶĸ�����ÿһλ������ʧ����˽�1000�ݵ���������x��
	//}

	//���������
	float x;
	for (float i = 0; i <= 100; i++)
	{
		x = i / 100;
		printf("%f\n", x);
	}
	//ѭ���жϱ�����׼Ӧ��ʹ�����Ͷ���Ҫ�ø�����
	return 0;
}