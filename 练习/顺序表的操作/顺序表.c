#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct {
	int* p;
	int len;//线性表的总长度
	int cn;//当前元素个数
}Arr;
int Full(Arr* arr) {
	if (arr->cn == arr->len)
		return 1;
	return 0;
}
void InitArr(Arr* arr, int n) {
	arr->p = (int*)malloc(sizeof(int) * n);
	if (arr->p == NULL) {
		printf("动态内存分配失败！");
		exit(-1);
	}
	else {
		arr->len = n;
		arr->cn = 0;
	}
}
void Show(Arr* arr) {
	if (arr->cn == 0) {
		printf("数组为空！");
	}
	else {
		for (int i = 0; i < arr->cn; i++) {
			printf("%d ", arr->p[i]);
		}
		printf("\n");
	}
}
int Size(Arr* arr) {
	if (arr->len != 0)
	{
		return arr->len;
	}
	return 0;
}
void Append(Arr* arr, int val) {
	if (Full(arr)) {
		printf("数组已满，无法添加元素！");
		printf("是否扩容？1.是 2.否");
		int i;
		scanf("%d", &i);
		switch (i) {
		case 1:
			if (Size(arr) == 0 || arr->p == NULL) {
				exit(-1);
			}
			arr->p = (int*)realloc(arr->p, sizeof(int) * Size(arr) * 2);
			arr->p[arr->cn] = val;
			arr->cn++;
		case 2:;
		}
	}
	else {
		arr->p[arr->cn] = val;
		arr->cn++;
	}
}
void Insert(Arr* arr, int pos, int val) {
	if (pos<1 || pos>arr->cn + 1) {
		printf("插入位置不合法！");
	}
	else if (Full(arr)) {
		printf("数组已满，无法插入元素！");
	}
	else {
		for (int i = arr->cn - 1; i >= pos - 1; i--) {
			arr->p[i + 1] = arr->p[i];
		}
		arr->p[pos - 1] = val;
		arr->cn++;
	}
}
void Delete(Arr* arr, int val) {
	int flag = 0;
	int i;
	for (i = 0; i < arr->cn; i++) {
		if (arr->p[i] == val) {
			flag = 1;
		}
		break;
	}
	if (flag == 1) {
		for (int j = i; j <= arr->cn - 1; j++) {
			arr->p[j - 1] = arr->p[j];
		}
		arr->cn--;
	}
	else {
		printf("顺序表中没有您要删除的元素！");
	}
}
void Delete2(Arr* arr, int pos) {
	if (pos<1 || pos>arr->cn) {
		printf("您想要删除的元素位置不存在！");
	}
	else {
		for (int i = pos - 1; i <= arr->cn - 1; i++) {
			arr->p[i - 1] = arr->p[i];
		}
		arr->cn--;
	}
}
void Sort(Arr* arr) {
	int i, j;
	for (i = 0; i < arr->cn - 1; i++) {
		for (j = 0; j < arr->cn - 1 - i; j++) {
			if (arr->p[j] > arr->p[j + 1]) {
				int t = arr->p[j];
				arr->p[j] = arr->p[j + 1];
				arr->p[j + 1] = t;
			}
		}
	}
}
void Find(Arr* arr, int val) {
	int flag = 0;
	for (int i = 0; i < arr->cn; i++) {
		if (arr->p[i] == val) {
			printf("该元素的下标为%d\n", i + 1);
		}
		flag = 1;
	}
	if (flag == 0) printf("顺序表中无该元素！\n");
}
void Reverse(Arr* arr) {
	int i, j = arr->cn - 1;
	for (i = 0; i < j; i++) {
		int t;
		t = arr->p[i];
		arr->p[i] = arr->p[j];
		arr->p[j] = t;
		j--;
	}
}
void Modify(Arr* arr, int pos, int val) {
	arr->p[pos - 1] = val;
}
int main(void) {
	Arr arr;
	int n = 6;//为数组分配n个int类型个字节的空间
	InitArr(&arr, n);
	/*Show(&arr);*/
	/*printf("%d", arr.len);*/
	Append(&arr, 1);//追加元素
	Append(&arr, 9);
	Append(&arr, 7);
	Append(&arr, 5);
	Append(&arr, 3);
	/*printf("%d\n", arr.cn);*/
	Show(&arr);
	Insert(&arr, 2, 0);//在第二个元素前插入元素0
	Show(&arr);
	//Delete(&arr, 1);//删除指定元素
	//Show(&arr);
	//Delete2(&arr, 2);//删除指定位置的元素
	//Show(&arr);
	/*Append(&arr, 6);
	Show(&arr);*/
	Sort(&arr);//排序
	Show(&arr);
	Find(&arr, 5);//查找数组中是否存在该元素
	Reverse(&arr);//逆置该顺序表
	Show(&arr);
	Modify(&arr, 5, 10);//修改顺序表位置5的元素为10
	Show(&arr);
	return 0;
}