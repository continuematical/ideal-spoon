#include<stdio.h>
#include<malloc.h>

#define N 2000
int isPrimeNumber(int n);

int main() {
	int primeNumber[N] = { 0 };
	int k = 0;//ËØÊı¸öÊı
	for (int i = 2; i < N; i++) {
		if (isPrimeNumber(i)) {
			primeNumber[k++] = i;
		}
	}
	int* dif = (int*)malloc((k - 1) * sizeof(int));
	for (int i = 1; i < k; i++) {
		//printf("%d ", primeNumber[i]);
		dif[i - 1] = primeNumber[i] - primeNumber[i - 1];
	}

	int res = 0;
	for (int i = 0; i < k - 1; i++) {
		int sum = 0;
		for (int j = i; j < k - 1; j++) {
			sum += dif[j];
			if (sum >= 1898) {
				break;
			}
		}
		if (sum == 1898) {
			res++;
		}
		else {
			continue;
		}
	}

	printf("%d", res);

	return 0;
}
int isPrimeNumber(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}