#include<stdio.h>
int main()
{
	int n, a[10000] = { 0 }, k, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &k);
		a[k] = k;
	}
	for (i = 0; i < 10000; i++) {
		if (a[i] != 0) {
			printf("%d ", a[i]);
		}
	}
	return 0;
}