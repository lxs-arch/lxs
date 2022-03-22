#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct {
	int* p;
	int len;//���Ա���ܳ���
	int cn;//��ǰԪ�ظ���
}Arr;
int Full(Arr* arr) {
	if (arr->cn == arr->len)
		return 1;
	return 0;
}
void InitArr(Arr* arr, int n) {
	arr->p = (int*)malloc(sizeof(int) * n);
	if (arr->p == NULL) {
		printf("��̬�ڴ����ʧ�ܣ�");
		exit(-1);
	}
	else {
		arr->len = n;
		arr->cn = 0;
	}
}
void Show(Arr* arr) {
	if (arr->cn == 0) {
		printf("����Ϊ�գ�");
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
		printf("�����������޷����Ԫ�أ�");
		printf("�Ƿ����ݣ�1.�� 2.��");
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
		printf("����λ�ò��Ϸ���");
	}
	else if (Full(arr)) {
		printf("�����������޷�����Ԫ�أ�");
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
		printf("˳�����û����Ҫɾ����Ԫ�أ�");
	}
}
void Delete2(Arr* arr, int pos) {
	if (pos<1 || pos>arr->cn) {
		printf("����Ҫɾ����Ԫ��λ�ò����ڣ�");
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
			printf("��Ԫ�ص��±�Ϊ%d\n", i + 1);
		}
		flag = 1;
	}
	if (flag == 0) printf("˳������޸�Ԫ�أ�\n");
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
	int n = 6;//Ϊ�������n��int���͸��ֽڵĿռ�
	InitArr(&arr, n);
	/*Show(&arr);*/
	/*printf("%d", arr.len);*/
	Append(&arr, 1);//׷��Ԫ��
	Append(&arr, 9);
	Append(&arr, 7);
	Append(&arr, 5);
	Append(&arr, 3);
	/*printf("%d\n", arr.cn);*/
	Show(&arr);
	Insert(&arr, 2, 0);//�ڵڶ���Ԫ��ǰ����Ԫ��0
	Show(&arr);
	//Delete(&arr, 1);//ɾ��ָ��Ԫ��
	//Show(&arr);
	//Delete2(&arr, 2);//ɾ��ָ��λ�õ�Ԫ��
	//Show(&arr);
	/*Append(&arr, 6);
	Show(&arr);*/
	Sort(&arr);//����
	Show(&arr);
	Find(&arr, 5);//�����������Ƿ���ڸ�Ԫ��
	Reverse(&arr);//���ø�˳���
	Show(&arr);
	Modify(&arr, 5, 10);//�޸�˳���λ��5��Ԫ��Ϊ10
	Show(&arr);
	return 0;
}