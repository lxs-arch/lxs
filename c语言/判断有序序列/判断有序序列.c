#include <stdio.h>
int main()
{
	int n, i, a[100], c = 0, b = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n - 1; i++) {
		if (a[i] < a[i + 1]) {
			b++;
		}
		else c++;
	}
	if (b == n - 1 || c == n - 1) {
		printf("sorted");
	}
	else printf("unsorted");
	return 0;
}