#include<stdio.h>
typedef char ElemType;
#define MAXSIZE 50
typedef struct SqList {
	int length;
	ElemType arr[MAXSIZE];
}SqList;
int main() {
	int i, j;
	SqList A, B;
	scanf("%d %d", &A.length, &B.length);
	getchar();
	for (i = 0; i < A.length; i++) {
		scanf("%c", &A.arr[i]);
	}
	getchar();
	for (j = 0; j < B.length; j++) {
		scanf("%c", &B.arr[j]);
	}
	if (A.length > B.length) {
		printf("A����B");
		return 0;
	}
	else if (A.length < B.length) {
		printf("AС��B");
		return 0;
	}
	else if (A.length == B.length) {
		for (i = 0; i < A.length;) {
			for (j = 0; j < A.length; j++) {
				if (A.arr[i] > B.arr[j]) {
					printf("A����B");
					return 0;
				}
				else if (A.arr[i] < B.arr[j]) {
					printf("AС��B");
					return 0;
				}
				i++;
			}
		}
		while (i == A.length) {
			printf("A����B");
			return 0;
		}
	}
	return 0;
}
