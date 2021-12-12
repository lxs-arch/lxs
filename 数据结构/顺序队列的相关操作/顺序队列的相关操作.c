#include<stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int Status;
typedef int QElemType;
typedef struct {
	QElemType data[MAXSIZE];
	int front;
	int rear;
}SqQueue;
Status InitQueue(SqQueue* Q) {
	Q->front = 0;
	Q->rear = 0;
	return OK;
}
Status EnQueue(SqQueue* Q, QElemType e) {
	if ((Q->rear + 1) % MAXSIZE == Q->front) return ERROR;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return OK;
}
Status Print(SqQueue Q) {
	int i;
	i = Q.front;
	while (i != Q.rear)
	{
		printf("%d ", Q.data[i]);

		i = (i + 1) % MAXSIZE;
	}
	printf("\n");
}
Status QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
Status GetHead(SqQueue Q) {
	if (Q.front == Q.rear) return ERROR;
	return Q.data[Q.front];
}
Status DeQueue(SqQueue* Q) {
	if (Q->front == Q->rear) return ERROR;
	Q->front = (Q->front + 1) % MAXSIZE;
	return OK;
}
Status QueueEmpty(SqQueue Q) {
	if (Q.front == Q.rear) return TRUE;
	return FALSE;
}
Status Locate(SqQueue Q, QElemType e) {
	int i;
	for (i = Q.front; i != Q.rear; i = (i + 1) % MAXSIZE) {
		if (Q.data[i] == e) return i;
	}
	return FALSE;
}
int main() {
	SqQueue Q;
	InitQueue(&Q);
	int j;
	for (j = 1; j <= 5; j++) {
		EnQueue(&Q, j);
	}
	//printf("%d \n",Q.data[Q.rear-1]);
	Print(Q);
	printf("队列的长度为：%d\n", QueueLength(Q));
	printf("队头元素为：%d\n", GetHead(Q));
	DeQueue(&Q);
	printf("删除队头元素后，队列元素为：");
	Print(Q);
	//printf("队头元素为：%d\n", GetHead(Q));
	//printf("%d \n", Q.data[Q.rear - 1]);
	printf("队列的长度为：%d\n", QueueLength(Q));
	printf("是否为空队列：1.空队列 0.非空队列:%d\n", QueueEmpty(Q));
	int e;
	printf("请输入要查找的元素:");
	scanf("%d", &e);
	if (Locate(Q, e)) printf("该元素的下标为：%d\n", Locate(Q, e));
	else printf("队列中无该元素！\n");
	//printf("%d %d", Q.front, Q.rear);
	DeQueue(&Q);
	DeQueue(&Q);
	EnQueue(&Q, 3);
	EnQueue(&Q, 7);
	EnQueue(&Q, 0);
	printf("删除队头元素1，2，3插入元素3，7，0后，队列为：");
	Print(Q);
	printf("队列的长度为：%d\n", QueueLength(Q));
	return 0;
}
