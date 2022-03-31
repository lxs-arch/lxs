#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* next;
}Node, * LinkList;
void Init(LinkList* L) {
	*L = (LinkList)malloc(sizeof(Node));
	if (*L == NULL) {
		printf("��̬�ڴ����ʧ�ܣ�");
		exit(-1);
	}
	(*L)->next = NULL;
}
void Insert(LinkList* L, int pos, int val) {
	int j;
	LinkList p, s;
	p = *L;
	j = 1;
	while (p && j < pos)     /* Ѱ�ҵ�i����� */
	{
		p = p->next;
		++j;
	}
	if (!p || j > pos)
		printf("����λ�ò���ȷ��");   /* ��i��Ԫ�ز����� */
	s = (LinkList)malloc(sizeof(Node));
	while (!s) {
		exit(-1);
	}
	s->data = val;
	s->next = p->next;      /* ��p�ĺ�̽�㸳ֵ��s�ĺ��  */
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
		printf("Ԫ��λ�ò����ڣ�");
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
			printf("��Ԫ�ص��±�Ϊ��%d\n", j);
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
	int e;//���ر�ɾ��Ԫ�ص�ֵ
	int pos;//�����ɾ����λ��
	Init(&L);
	int n;//�ڵ����
	int a;
	printf("�������ʼ����ڵ����:");
	scanf("%d", &n);
	int val;
	for (int i = 0; i < n; i++) {
		printf("��%d���ڵ��ֵ��", i + 1);
		scanf("%d", &val);
		Insert(&L, 1, val);
		/*Print(L);*/
	}
	Print(L);
	/*printf("��������Ҫɾ����Ԫ��λ�ã�");
	scanf("%d", &pos);
	Delete(&L, pos, &e);
	printf("��ɾ����%dλ�õ�Ԫ��ֵΪ:%d\n", pos, e);
	printf("ɾ����Ԫ�غ�����Ϊ��");
	Print(L);
	int len=Length(L);
	printf("ɾ����Ԫ�غ�������Ϊ��%d\n",len);
	Sort(&L, Length(L));
	printf("���������Ϊ��");
	Print(L);
	printf("������Ҫ���ҵ�Ԫ��ֵ��");
	scanf("%d", &a);
	Locate(L, a);*/
	printf("������Ҫ�޸�Ԫ�ص��±�:");
	scanf("%d", &pos);
	printf("�������޸ĺ��ֵ��");
	scanf("%d", &a);
	Modify(&L, pos, a);
	printf("�޸ĺ�����Ϊ��");
	Print(L);

	return 0;
}
