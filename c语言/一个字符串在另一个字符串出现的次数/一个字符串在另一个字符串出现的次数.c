#include<stdio.h>
#include<string.h>
int main() {
	int n = 0;
	char* s1 = "aabbccaaabbccaaaabbc";
	char s2[] = "bb";
	while (*s1 != '\0') {
		s1 = strstr(s1, s2);
		if (s1 != NULL) {
			n = n + 1;
			s1 = s1 + strlen(s2);
		}
		else break;
	}
	printf("%d", n);
	return 0;
}