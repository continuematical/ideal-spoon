#include<stdio.h>
#define N 10000
int calculate(int n);

int main() {
	int arr[9] = { 0 };
	for (int i = 1; i < N; i++) {
		arr[calculate(i) - 1]++;
	}
	for (int i = 0; i < 9; i++) {
		printf("%d : %d\n", i + 1, arr[i]);
	}
	return 0;
}

int calculate(int n) {
	if (n / 10 == 0) {
		return n;
	}
	int num = 1;
	while (n) {
		int temp = n % 10;
		if (temp) {
			num *= temp;
		}
		n /= 10;
	}
	calculate(num);
}