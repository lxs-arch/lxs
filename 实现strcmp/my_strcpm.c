#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int my_strcmp(const char* s1, const char* s2) {
	while (*s1 == *s2) {
		if (s1 == '\0') {
			return 0;
		}
		s1++;
		s2++;
	}
	if (*s1 > *s2) {
		return 1;
	}
	else return -1;
}
int main() {
	char arr1[10], arr2[10];
	scanf("%s %s", &arr1, &arr2);
	int ret = my_strcmp(arr1, arr2);
	if (ret == 0) {
		printf("arr1��arr2���");
	}
	else if (ret == 1) {
		printf("arr1����arr2");
	}
	else printf("arr1С��arr2");
	return 0;
}