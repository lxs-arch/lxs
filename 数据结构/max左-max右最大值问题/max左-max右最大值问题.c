#include<stdio.h>
int main()
{
	int a[5] = { 5,2,7,9,4 };
	int max = 0;
	for (int i = 0; i < 5; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	int x, y;
	if (max - a[0] > 0) {
		x = max - a[0];
	}
	else {
		x = a[0] - max;
	}
	if (max - a[4] > 0) {
		y = max - a[4];
	}
	else y = a[4] - max;
	if (x >= y) {
		printf("%d \n", x);
	}
	else printf("%d \n", y);
	return 0;
}