#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* next;
}Node, * LinkList;
void Init(LinkList* L) {
	*L = (LinkList)malloc(sizeof(Node));
	if (*L == NULL) {
		printf("动态内存分配失败！");
		exit(-1);
	}
	(*L)->next = NULL;
}
void Insert(LinkList* L, int pos, int val) {
	int j;
	LinkList p, s;
	p = *L;
	j = 1;
	while (p && j < pos)     /* 寻找第i个结点 */
	{
		p = p->next;
		++j;
	}
	if (!p || j > pos)
		printf("插入位置不正确！");   /* 第i个元素不存在 */
	s = (LinkList)malloc(sizeof(Node));
	while (!s) {
		exit(-1);
	}
	s->data = val;
	s->next = p->next;      /* 将p的后继结点赋值给s的后继  */
	p->next = s;

}
void Print(LinkList L) {
	LinkList p = L->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void Delete(LinkList* L, int pos, int* e) {
	LinkList p = *L;
	int j = 1;
	while (j < pos && p->next) {
		p = p->next;
		j++;
	}
	if (j > pos || p->next == NULL) {
		printf("元素位置不存在！");
		exit(-1);
	}
	LinkList q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);

}
void Sort(LinkList* L, int len) {
	LinkList p;
	for (int i = 0; i < len - 1; i++) {
		p = (*L)->next;
		for (int j = 0; j < len - i - 1; j++) {
			if (p->data > p->next->data) {
				int t = p->data;
				p->data = p->next->data;
				p->next->data = t;
			}
			p = p->next;
		}
	}
}
int Length(LinkList L) {
	LinkList p = L;
	int n = 0;
	while (p->next) {
		p = p->next;
		n++;
	}
	return n;
}
void Locate(LinkList L, int a) {
	LinkList p = L->next;
	int j = 1;
	while (p) {
		if (p->data == a) {
			printf("该元素的下标为：%d\n", j);
			return;
		}
		else {
			p = p->next;
			j++;
		}
	}
}
void Modify(LinkList* L, int pos, int a) {
	LinkList p = L;
	int j = 1;
	while (p)
	{
		if (pos == j)
		{
			p->data = a;
		}
		else
		{
			p = p->next;
			j++;
		}
	}

}
int main(void) {
	LinkList L;
	int e;//返回被删除元素的值
	int pos;//插入或删除的位置
	Init(&L);
	int n;//节点个数
	int a;
	printf("请输入初始链表节点个数:");
	scanf("%d", &n);
	int val;
	for (int i = 0; i < n; i++) {
		printf("第%d个节点的值：", i + 1);
		scanf("%d", &val);
		Insert(&L, 1, val);
		/*Print(L);*/
	}
	Print(L);
	/*printf("请输入您要删除的元素位置：");
	scanf("%d", &pos);
	Delete(&L, pos, &e);
	printf("您删除的%d位置的元素值为:%d\n", pos, e);
	printf("删除该元素后，链表为：");
	Print(L);
	int len=Length(L);
	printf("删除该元素后，链表长度为：%d\n",len);
	Sort(&L, Length(L));
	printf("排序后链表为：");
	Print(L);
	printf("请输入要查找的元素值：");
	scanf("%d", &a);
	Locate(L, a);*/
	printf("请输入要修改元素的下标:");
	scanf("%d", &pos);
	printf("请输入修改后的值：");
	scanf("%d", &a);
	Modify(&L, pos, a);
	printf("修改后，链表为：");
	Print(L);

	return 0;
}
