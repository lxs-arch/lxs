#include<stdio.h>
int main() {
	int a[10], i, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int k;
	scanf("%d", &k);
	for (i = 0; i < n; i++) {
		if (a[i] != k) {
			printf("%d ", a[i]);
		}
	}

	return 0;
}