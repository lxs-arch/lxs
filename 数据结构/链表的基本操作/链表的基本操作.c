#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>
#define ERROR 0
#define TRUE 1
#define OK 1
#define FALSE 0
typedef int Status;
typedef int ElemType;
typedef struct Node {
	ElemType data;
	struct Node* next;
}Node,*LinkList;
Status InitList(LinkList* L) {
	*L = (LinkList)malloc(sizeof(Node));
	if (*L == NULL) return ERROR;
	(*L)->next = NULL;
	return OK;
}
Status ListInsert(LinkList* L, int i, ElemType e)
{
	int j;
	LinkList p, s;
	p = *L;
	j = 1;
	while (p && j < i)     /* 寻找第i个结点 */
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;   /* 第i个元素不存在 */
	s = (LinkList)malloc(sizeof(Node));
	while (!s) {
		exit(-1);
	}
	s->data = e;
	s->next = p->next;      /* 将p的后继结点赋值给s的后继  */
	p->next = s;          /* 将s赋值给p的后继 */
	return OK;
}
Status ListPrint(LinkList L) {
     LinkList p = L->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
int Listlength(LinkList L) {
	LinkList p=L->next;
	int i=0;
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}
Status ListDelete(LinkList* L, int i)
{
	int j;
	LinkList p, q;
	p = *L;
	j = 1;
	while (p->next && j < i)	/* 遍历寻找第i个元素 */
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
		return ERROR;           /* 第i个元素不存在 */
	q = p->next;
	p->next = q->next;			/* 将q的后继赋值给p的后继 */
	free(q);                    /* 让系统回收此结点，释放内存 */
	return OK;
}
int LocateElem(LinkList L, ElemType e) {
	LinkList p = L->next;
	int i=0;
	while (p) {
		i++;
		if (p->data == e) {
			return i;
			p = p->next;
		}
		else return -1;
	}
}
Status ClearList(LinkList* L) {
	LinkList p, q;
	p = (*L)->next;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}
void CreatListHead(LinkList* L, int n) {
	LinkList p;
	srand(time(0));
	int i;
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for (i = 0; i < n; i++) {
		p =(LinkList) malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next =(*L)->next;
		(*L)->next=p;
	}
}
void CreatListTail(LinkList* L, int n) {
	LinkList p,r;
	srand(time(0));
	int i;
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for (i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		r->next = p;
		r = p;
	}
	r ->next = NULL;
}
int main() {
	LinkList L;
	int i,j;
	i=InitList(&L);//初始化链表
	for (j = 1; j < 10; j++) {
		ListInsert(&L, 1, j);
	}//在表头插入元素
	ListPrint(L);
	i= Listlength(L);//输出链表长度
	j = 5;
	printf("链表的长度为%d\n", j);
	ListDelete(&L, 5);//删除表中第五个元素
	i = Listlength(L);
	printf("删除第%d个元素后链表的长度为%d\n",j, i);
	i=LocateElem(L, 4);//在链表里查找有没有4
	if (i == -1) {
		printf("链表里没有该元素\n");
	}
	else printf("该元素的下标为%d\n", i);
	ClearList(&L);//清空链表
	i = Listlength(L);
	printf("清空后链表的长度为：%d\n", i);
	CreatListHead(&L,10);//头插法 
	ListPrint(L);
	ClearList(&L);
	CreatListTail(&L, 10);//尾插法 
	ListPrint(L);
	return 0;
}
