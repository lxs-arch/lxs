#include<stdio.h>
void bubble_sort(int* a, int n) {
	int i, j;
	int temp = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (a[j + 1] > a[j]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int a[5] = { 3,7,1,2,9 };
	int n = 5;
	bubble_sort(a, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}