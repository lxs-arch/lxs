#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
#include<string.h>
#define List_size 5
#define ListIncrement 3
typedef struct {
	int* List;
	int length;//当前长度
	int List_len;//分配的总长度；
}Sqlist;
void InitList(Sqlist* L) {
	L->List = (int*)malloc(List_size * sizeof(int));
	if (L->List == NULL) {
		printf("动态内存分配失败！");
		exit(-1);
	}

	L->length = 0;
	L->List_len = List_size;
}
void Insert_List(Sqlist* L, int pos, int data) {
	if (pos<1 || pos>L->length + 1) {
		printf("您插入元素的位置不合法！");
		exit(-1);
	}
	if (L->length >= L->List_len) {
		printf("内存已满需要扩容！\n");
		L->List = (int*)realloc(L->List, (L->List_len + ListIncrement) * sizeof(int));
		if (L->List == NULL) {
			printf("动态内存分配失败！");
			exit(-1);
		}
		L->List_len += ListIncrement;
	}
	for (int i = L->length - 1; i >= pos - 1; i--) {
		L->List[i + 1] = L->List[i];
	}
	L->List[pos - 1] = data;
	L->length++;
}
void List_delete(Sqlist* L, int pos) {
	if (pos<1 || pos>L->length) {
		printf("您删除元素的位置不合法！");
		exit(-1);
	}
	for (int i = pos; i < L->length; i++) {
		L->List[i - 1] = L->List[i];
	}
	L->length--;
}
void List_traverse(Sqlist* L) {
	for (int i = 0; i < L->length; i++) {
		printf("%d ", L->List[i]);
	}
	printf("\n");
}
void List_Sort(Sqlist* L) {
	int t;
	for (int i = 0; i < L->length; i++) {
		for (int j = 0; j < L->length - i - 1; j++) {
			if (L->List[j] > L->List[j + 1]) {
				t = L->List[j];
				L->List[j] = L->List[j + 1];
				L->List[j + 1] = t;
			}
		}
	}
}
void List_modify(Sqlist* L, int pos, int val) {
	if (pos<1 || pos>L->length + 1) {
		printf("您修改的元素位置不合法！");
		exit(-1);
	}
	L->List[pos - 1] = val;
}
int Getval(Sqlist L, int pos) {
	if (pos<1 || pos>L.length + 1) {
		printf("您查找的元素位置不合法！");
		exit(-1);
	}
	return L.List[pos - 1];
}
int Locate(Sqlist L, int val) {
	for (int i = 0; i < L.length; i++) {
		if (L.List[i] == val) {
			return i + 1;
		}
	}
	return 0;
}
int main(void) {
	Sqlist L;
	int data;
	int pos;
	int val;
	InitList(&L);
	for (int i = 0; i < List_size; i++) {
		printf("请输入第%d个元素：", i + 1);
		scanf("%d", &data);
		Insert_List(&L, 1, data);
	}
	printf("请输入您想插入的元素位置:");
	scanf("%d", &pos);
	printf("请输入您想插入的值：");
	scanf("%d", &val);
	Insert_List(&L, pos, val);
	/*printf("%d\n", L.length);
	printf("%d\n", L.List_len);*/
	/*printf("%d\n", L.List[1]);*/
	/*printf("%p\n", &L.List[1]);*/
	printf("插入后，顺序表为:");
	List_traverse(&L);
	printf("请输入您想删除的元素位置:");
	scanf("%d", &pos);
	List_delete(&L, pos);
	printf("删除第%d个位置的元素后，顺序表为：", pos);
	List_traverse(&L);
	List_Sort(&L);
	printf("排序后，顺序表为:");
	List_traverse(&L);
	printf("请输入您需要修改的元素位置:");
	scanf("%d", &pos);
	printf("请输入您想修改的值：");
	scanf("%d", &val);
	List_modify(&L, pos, val);//修改第一个元素的值为0；
	printf("修改后，顺序表为:");
	List_traverse(&L);
	printf("请输入您想要获取元素的位置：");
	scanf("%d", &pos);
	printf("顺序表第%d个元素为：%d\n", pos, Getval(L, pos));
	printf("请输入您想要查找的元素：");
	scanf("%d", &val);
	if (Locate(L, val) == 0) {
		printf("顺序表中没有您想要查找的值！\n");
	}
	else printf("该元素的下标为：%d\n", Locate(L, val));

}