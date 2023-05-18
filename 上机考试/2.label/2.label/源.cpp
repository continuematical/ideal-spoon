#include<stdio.h>

int main() {
	int n, k;
	int rank = 1;//排名
	int m = 0;//记录登记过的数大小
	printf("请输入数组个数：");
	scanf_s("%d", &n);
	int arr[2][100] = { 0 };
	//数组赋值
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[0][i]);
	}
	
	for (int i = 0; i < n; i++) {
		if (arr[1][i] != 0) {
			continue;
		}
		k = i;
		for (int j = 0; j < n; j++) {
			if (arr[1][j] == 0 && arr[0][j] < arr[0][k]) {
				k = j;
			}
		}
		arr[1][k] = rank++;
		m++;
		for (int j = 0; j < n; j++) {
			if (arr[1][j] == 0 && arr[0][j] == arr[0][k]) {
				arr[1][j] = arr[1][k];
				m++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (!arr[1][i]) {
			arr[1][i] = rank;
		}
	}

	//输出排名
	for (int i = 0; i < n; i++) {
		printf("%d", arr[1][i]);
	}
	return 0;
}