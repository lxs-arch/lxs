#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
int main(void) {
	int n;
	scanf("%d", &n);
	int i = 0, temp = 0;
	struct Node* pHead = NULL, * pTail = NULL;
	for (i = 0; i < n; i++) {
		scanf("%d ", &temp);
		struct Node* L = (struct Node*)malloc(sizeof(struct Node));
		if (L == NULL) {
			printf("½Úµã¿ª±ÙÊ§°Ü");
			exit(-1);
		}
		L->data = temp;
		L->next = NULL;
		if (pHead == NULL) {
			pHead = L;
			pTail = L;
		}
		else {
			pTail->next = L;
			pTail = L;
		}
	}
	int t;
	scanf("%d", &t);
	struct Node* cur = pHead;
	while (cur) {
		if (cur->data == t) {
			n--;
		}
		cur = cur->next;
	}
	printf("%d\n", n);
	cur = pHead;
	while (cur) {
		if ((cur->data) != t) {
			printf("%d ", cur->data);
		}
		cur = cur->next;
	}
	cur = pHead;
	struct Node* p;
	while (cur) {
		p = cur;
		cur = cur->next;
		free(p);
	}
	return 0;
}