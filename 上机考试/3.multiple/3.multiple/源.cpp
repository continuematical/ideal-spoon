#define N 100
#include<stdio.h>
#include<string.h>

void CharTranslateToInt(int* p, char* pc, int i);

int main() {
	char str[100];
	int number1[N] = { 0 };
	int number2[N] = { 0 };
	int res[2 * N] = { 0 };
	printf("请输入被乘数：");
	scanf_s("%s", str);
	int length1 = strlen(str);

	//放入数组
	for (int i = 0; i < length1; i++) {
		CharTranslateToInt(number1, str, i);
	}

	printf("请输入乘数：");
	scanf_s("%s", str);
	int length2 = strlen(str);

	for (int i = 0; i < length2; i++) {
		CharTranslateToInt(number2, str, i);
	}
	
	for (int i = length1 - 1; i >= 0; i--) {
		for (int j = length2 - 1; j >= 0; j--) {
			int digit = length1 + length2 - i - j - 2;
			res[digit] += number1[i] * number2[j];
		}
	}
	//每一位满十往上进一
	for (int i = 0; i < 2 * N - 1; i++) {
		int ge = res[i] % 10;
		int shi = res[i] / 10;
		res[i] = ge;
		res[i + 1] += shi;
	}

	//遍历找到第一位非零结果
	int k = 0;
	for (int i = 2 * N - 1; i >= 0; i--) {
		if (res[i]) {
			k = i;
			break;
		}
	}

	//打印结果
	for (int i = k; i >= 0; i--) {
		printf("%d", res[i]);
	}
	return 0;
}

void CharTranslateToInt(int* p, char* pc, int i) {
	p[i] = (int)(pc[i]) - 48;
}