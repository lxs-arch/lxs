#include<stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int Status;
typedef char SElemType;
typedef struct StackNode {
	SElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;
typedef struct {
	LinkStackPtr top;
	int count;
}LinkStack;
Status InitStack(LinkStack* S) {
	S->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!S->top) return ERROR;
	S->top = NULL;
	S->count = 0;
}
Status Push(LinkStack* S, SElemType e) {
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!s) return ERROR;
	s->data = e;
	s->next = S->top;
	S->top = s;
	S->count++;
	return OK;
}
Status Print(LinkStack S) {
	LinkStackPtr p;
	p = S.top;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
Status Pop(LinkStack* S, int* e) {
	LinkStackPtr p;
	if (S->count == 0)
		return ERROR;
	*e = S->top->data;
	p = S->top;
	S->top = S->top->next;
	free(p);
	S->count--;
	return OK;
}
Status GetTop(LinkStack S, SElemType* e) {
	if (S.count == 0) return ERROR;
	*e = S.top->data;
	return OK;
}
Status StackLenth(LinkStack S) {
	return S.count;
}
Status StackEmpty(LinkStack S) {
	if (S.count == 0) return TRUE;
	return FALSE;
}
int main() {
	LinkStack s;
	InitStack(&s);
	int j;
	int e;
	for (j = 1; j <= 10; j++) {
		Push(&s, j);
	}
	printf("栈中的元素为：\n");
	Print(s);
	Pop(&s, &e);
	printf("弹出栈顶元素后，栈中元素为：");
	Print(s);
	GetTop(s, &e);
	printf("栈顶元素为：%d,栈的长度为：%d", e, StackLenth(s));
	printf("\n");
	printf("栈是否为空（1.空 0.非空）：%d", StackEmpty(s));
	return 0;
}