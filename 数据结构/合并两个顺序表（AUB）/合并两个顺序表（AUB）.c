#include<stdio.h>
#include<malloc.h>
#define LENGTH 10//初始表长
typedef struct {
	int* list;
	int length;//有效元素个数
}Sqlist;
void Init_List(Sqlist*L) {
	L->list = (int*)malloc(LENGTH*sizeof(int));
	L->length = 0;
}
void Creat_List(Sqlist* L,int n){
	int i;
	int val;//元素值
	for (i = 0; i < n; i++) {
		printf("请输入第%d个元素的值:",i+1);
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
				n++;//n=L1的长度说明L1中没有该元素，否则L1中有L1->length-n个该元素
			}
		}
		if (n == L1->length) {
			Insert_List(L1, L2->list[i]);//将该元素插入到L1的尾部
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
	int n;//需要的元素个数
	Init_List(&L1);
	Init_List(&L2);
	printf("请输入第一个线性表的元素个数:");
	scanf("%d", &n);
	Creat_List(&L1,n);
	/*Print_List(&L1);*/
	printf("请输入第2个线性表的元素个数:");
	scanf("%d", &n);
	Creat_List(&L2, n);
	Init_List(&L3);
	Union_List(&L1, &L2);//将所有不在L1中但在L2中的元素插入到L1中
	printf("合并后L1为：");
	Print_List(&L1);
	Sort_List(&L1);
	printf("排序后L1为：");
	Print_List(&L1);
	/*Print_List(&L2);*/
}