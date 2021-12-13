#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define MAXSIZE 20;
typedef int Status;
typedef int QElemType;
typedef struct QNode {
	QElemType data;
	struct QNode* next;
}QNode, * QueuePtr;
typedef struct {
	QueuePtr front, rear;
}LinkQueue;
Status InitQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front) return ERROR;
	Q->front->next = NULL;
	return OK;
}
Status EnQueue(LinkQueue* Q, QElemType e) {
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (!s) return ERROR;
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
	return OK;
}
Status Print(LinkQueue Q) {
	QueuePtr p;
	p = Q.front->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
Status QueueLength(LinkQueue Q) {
	int i = 0;
	QueuePtr p = Q.front;
	while (p != Q.rear) {
		i++;
		p = p->next;
	}
	return i;
}
Status DeQueue(LinkQueue* Q) {
	if (Q->front == Q->rear) return ERROR;
	QueuePtr p = Q->front->next;
	Q->front->next = p->next;
	if (Q->rear == p) Q->rear = Q->front;
	free(p);
	return OK;
}
Status GetQueue(LinkQueue Q) {
	if (Q.front == Q.rear) return ERROR;
	return Q.front->next->data;

}
Status QueueEmpty(LinkQueue Q) {
	if (Q.front == Q.rear) return TRUE;
	return FALSE;
}
Status QueueClear(LinkQueue* Q) {
	QueuePtr p, q;
	Q->rear = Q->front;
	p = Q->front->next;
	Q->front->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	return OK;
}
int main() {
	LinkQueue q;
	if (InitQueue(&q)) printf("��ʼ�����гɹ�\n");
	else exit(-1);
	int i;
	for (i = 1; i <= 10; i++) {
		EnQueue(&q, i);
	}
	printf("����Ԫ��Ϊ��");
	Print(q);
	printf("��ͷԪ��Ϊ��%d\n", GetQueue(q));
	printf("���еĳ���Ϊ:%d\n", QueueLength(q));
	DeQueue(&q);
	printf("ɾ����ͷԪ�غ󣬶���Ϊ��");
	Print(q);
	printf("��ͷԪ��Ϊ��%d\n", GetQueue(q));
	printf("���г���Ϊ��%d\n", QueueLength((q)));
	printf("�����Ƿ�Ϊ�գ�0.�ǿ� 1.�� ����%d \n", QueueEmpty(q));
	QueueClear(&q);
	printf("��ն��к󣬶��г���Ϊ��%d\n", QueueLength(q));
	return 0;
}