#include<stdio.h>
int main() {
	int n, a[100], t, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &t);
	for (i = n - 1; i >= 0; i--) {
		if (a[i] > t) {
			a[i + 1] = a[i];
		}
		else {
			a[i + 1] = t;
			break;
		}
	}
	if (i < 0) {
		a[0] = t;
	}
	for (i = 0; i < n + 1; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
