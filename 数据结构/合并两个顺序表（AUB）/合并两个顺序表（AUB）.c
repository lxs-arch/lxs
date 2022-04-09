#include<stdio.h>
#include<malloc.h>
#define LENGTH 10//��ʼ��
typedef struct {
	int* list;
	int length;//��ЧԪ�ظ���
}Sqlist;
void Init_List(Sqlist*L) {
	L->list = (int*)malloc(LENGTH*sizeof(int));
	L->length = 0;
}
void Creat_List(Sqlist* L,int n){
	int i;
	int val;//Ԫ��ֵ
	for (i = 0; i < n; i++) {
		printf("�������%d��Ԫ�ص�ֵ:",i+1);
		scanf("%d", &val);
		L->list[i] = val;
		L->length++;
	}
}
void Print_List(Sqlist* L) {
	int i;
	for (i = 0; i < L->length; i++) {
		printf("%d ", L->list[i]);
	}
	printf("\n");
}
void Insert_List(Sqlist* L, int val) {
	L->list[L->length] = val;
	L->length++;
}
void Union_List(Sqlist *L1, Sqlist* L2) {
	int i,j;
	for (i = 0; i < L2->length; i++) {
		int n = 0;
		for (j = 0; j < L1->length; j++) {
			if (L1->list[j] != L2->list[i]) {
				n++;//n=L1�ĳ���˵��L1��û�и�Ԫ�أ�����L1����L1->length-n����Ԫ��
			}
		}
		if (n == L1->length) {
			Insert_List(L1, L2->list[i]);//����Ԫ�ز��뵽L1��β��
		}
	}
}
void Sort_List(Sqlist* L) {
	int i,j,t;
		for (i = 0; i < L->length-1; i++) {
			for (j = 0; j < L->length - 1 - i; j++) {
				if (L->list[j] > L->list[j + 1]) {
					t = L->list[j + 1];
					L->list[j + 1] = L->list[j];
					L->list[j] = t;
				}
			}
	}
}
int main(void) {
	Sqlist L1, L2,L3;
	int n;//��Ҫ��Ԫ�ظ���
	Init_List(&L1);
	Init_List(&L2);
	printf("�������һ�����Ա��Ԫ�ظ���:");
	scanf("%d", &n);
	Creat_List(&L1,n);
	/*Print_List(&L1);*/
	printf("�������2�����Ա��Ԫ�ظ���:");
	scanf("%d", &n);
	Creat_List(&L2, n);
	Init_List(&L3);
	Union_List(&L1, &L2);//�����в���L1�е���L2�е�Ԫ�ز��뵽L1��
	printf("�ϲ���L1Ϊ��");
	Print_List(&L1);
	Sort_List(&L1);
	printf("�����L1Ϊ��");
	Print_List(&L1);
	/*Print_List(&L2);*/
}