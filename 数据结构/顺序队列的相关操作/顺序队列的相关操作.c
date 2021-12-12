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
	printf("���еĳ���Ϊ��%d\n", QueueLength(Q));
	printf("��ͷԪ��Ϊ��%d\n", GetHead(Q));
	DeQueue(&Q);
	printf("ɾ����ͷԪ�غ󣬶���Ԫ��Ϊ��");
	Print(Q);
	//printf("��ͷԪ��Ϊ��%d\n", GetHead(Q));
	//printf("%d \n", Q.data[Q.rear - 1]);
	printf("���еĳ���Ϊ��%d\n", QueueLength(Q));
	printf("�Ƿ�Ϊ�ն��У�1.�ն��� 0.�ǿն���:%d\n", QueueEmpty(Q));
	int e;
	printf("������Ҫ���ҵ�Ԫ��:");
	scanf("%d", &e);
	if (Locate(Q, e)) printf("��Ԫ�ص��±�Ϊ��%d\n", Locate(Q, e));
	else printf("�������޸�Ԫ�أ�\n");
	//printf("%d %d", Q.front, Q.rear);
	DeQueue(&Q);
	DeQueue(&Q);
	EnQueue(&Q, 3);
	EnQueue(&Q, 7);
	EnQueue(&Q, 0);
	printf("ɾ����ͷԪ��1��2��3����Ԫ��3��7��0�󣬶���Ϊ��");
	Print(Q);
	printf("���еĳ���Ϊ��%d\n", QueueLength(Q));
	return 0;
}
