#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct Node {
	int* next;
	int data;
}Node, * PNode;
typedef struct Stack {
	PNode top;
	PNode bottom;
}Stack, * PStack;
void init(PStack s) {
	s->top = (PNode)malloc(sizeof(Node));
	if (!s->top) {
		printf("动态内存分配失败！");
		exit(-1);
	}
	else {
		s->bottom = s->top;
		s->top->next = NULL;
	}
}
void push(PStack s, int val) {
	PNode node = (PNode)malloc(sizeof(Node));
	if (!node) {
		printf("动态内存分配失败！");
		exit(-1);
	}
	node->data = val;
	node->next = s->top;
	s->top = node;
}
void traverse(PStack s) {
	PNode p = s->top;
	while (p != s->bottom) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void pop(PStack s, int* val) {
	if (empty(s)) {
		printf("当前栈空，无法执行出栈操作！");
	}
	else {
		PNode p = s->top;
		*val = p->data;
		s->top = p->next;
		free(p);
	}

}
int empty(PStack s) {
	if (s->bottom == s->top) {
		return 1;
	}
	else return 0;
}
void stacklength(PStack s, int* n) {
	PNode p = s->top;
	int i = 0;
	while (p != s->bottom) {
		i++;
		p = p->next;
	}
	*n = i;
}
void clear(PStack s) {
	if (empty(s)) {
		printf("当前栈已经为空！");
	}
	else {
		PNode p = s->top;
		PNode q;
		while (p != s->bottom) {
			q = p->next;
			free(p);
			p = q;
		}
		s->top = s->bottom;
		printf("栈清空完成！\n");
	}
}
int main(void) {
	Stack s;
	int val;
	int n;//栈的元素个数
	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	push(&s, 4);
	traverse(&s);
	stacklength(&s, &n);
	printf("栈的元素个数为：%d\n", n);
	pop(&s, &val);
	printf("出栈元素为：%d\n", val);
	stacklength(&s, &n);
	printf("栈的元素个数为：%d\n", n);
	printf("执行出栈操作后，栈的元素为：");
	traverse(&s);
	clear(&s);
	stacklength(&s, &n);
	printf("栈的元素个数为：%d\n", n);
	traverse(&s);

	return 0;
}