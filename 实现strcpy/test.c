#define _CRT_SECURE_NO_WARNINGS 1
//ʵ��strcpy����
#include <stdio.h>
#include<assert.h>
char* my_strcpy(char* s1, const char* s2) {
	assert(s1 && s2);
	char* ret = s1;
	while (*s1++ = *s2++;) {

		;
	}
	return ret;
}
int main() {
	char arr1[10] = "abc";
	char arr2[] = "edf";
	my_strcpy(arr1, arr2);//��arr2���Ƶ�arr1��
	printf("%s", arr1);
	return 0;
}