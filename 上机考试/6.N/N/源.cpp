#include<stdio.h>
#define N 200

int check(int n);

int main() {
	for (int i = 0; i <= N; i++) {
		if (check(i)) {
			printf("%d\n", i);
		}
	}
	return 0;
}

int check(int n) {
	char str[6] = { '0'};
	sprintf_s(str, "%05d", n * n);
	char* left = str;
	char* right = str + 4;
	while (*left == '0') {
		left++;
	}
	while (left <= right) {
		if (*left++ != *right--) {
			return 0;
		}
	}
	return 1;
}