#define _CRT_SECURE_NO_WARNINGS 1
//��1��2��3��4�����֣�����ɶ��ٸ�������ͬ�����ظ����ֵ���λ�������Ƕ��٣�
#include<stdio.h>
int main() {
	int a, b, c;
	for (a = 1; a <= 4; a++) {
		for (b = 1; b <= 4; b++) {
			for (c = 1; c <= 4; c++) {
				if (a != b && a != c && b != c) {
					int k = 100 * a + 10 * b + c;
					printf("%d\n", k);
				}
			}
		}
	}
	return 0;
}