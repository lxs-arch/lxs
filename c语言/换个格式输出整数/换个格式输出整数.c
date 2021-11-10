#include<stdio.h>
int main() {
	int n, i;
	scanf("%d", &n);
	int a, b, c;
	a = n / 100;
	b = (n - a * 100) / 10;
	c = n - a * 100 - b * 10;
	for (i = 0; i < a; i++) {
		printf("B");
	}
	for (i = 0; i < b; i++) {
		printf("S");
	}
	for (i = 1; i <= c; i++) {
		printf("%d", i);
	}

	return 0;
}
//让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（ < 10），换个格式来输出任一个不超过3位的正整数。例如234
//	应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4