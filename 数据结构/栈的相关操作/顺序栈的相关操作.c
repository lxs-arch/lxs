#include<stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int Status;
typedef int SElemType;
typedef struct {
	SElemType data[MAXSIZE];
	int top;
}SqStack;
InitStack(SqStack* S) {
	S->top = -1;
	return OK;
}
Status Push(SqStack* S, SElemType e) {
	if (S->top == MAXSIZE - 1) {
		return ERROR;
	}
	S->top++;
	S->data[S->top] = e;
	return OK;
}
Status StackTraverse(SqStack S) {
	int i = 0;
	while (i <= S.top) {
		printf("%d ", S.data[i++]);
	}
	printf("\n");
	return OK;
}
Status Pop(SqStack* S, SElemType* e) {
	if (S->top == -1)
		return ERROR;
	*e = S->data[S->top];
	S->top--;
	return OK;
}
Status GetTop(SqStack S, SElemType* e) {
	if (S.top == -1)
		return ERROR;
	*e = S.data[S.top];
	return OK;
}
Status StackLength(SqStack S) {
	return S.top + 1;
}
Status ClearStack(SqStack* S) {
	S->top = -1;
	return OK;
}
int main() {
	int j;
	SqStack s;
	if (InitStack(&s) == OK)
		for (j = 1; j <= 10; j++) {
			Push(&s, j);
		}
	printf("栈中元素为：");
	StackTraverse(s);
	int e;
	Pop(&s, &e);
	printf("删除栈顶元素后，栈中元素为：");
	StackTraverse(s);
	GetTop(s, &e);
	printf("栈顶元素为：%d\n", e);
	int length = StackLength(s);
	printf("栈的长度为：%d\n", length);
	ClearStack(&s);
	printf("清空栈后，栈的长度为：%d", StackLength(s));
	return 0;
}
