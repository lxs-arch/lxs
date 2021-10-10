#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
	int n;//包含6行数据
	scanf("%d", &n);
	int i, j, a[30][30] = { 0 };
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			a[i][0] = 1;
			a[i][i] = 1;
		}
	}
	for (i = 2; i < n; i++) {
		for (j = 1; j <= i - 1; j++) {
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			printf("%5d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

