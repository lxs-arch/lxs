#include<stdio.h>
int main() {
	int n = 0, a;
	scanf("%d", &a);
	while (a != 1) {
		if (a % 2 == 0) {
			a /= 2;
			n++;
		}
		else {
			a = (3 * a + 1) / 2;
			n++;
		}
	}
	printf("%d", n);
	return 0;
}