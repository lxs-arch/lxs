#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
#include<string.h>
#define List_size 5
#define ListIncrement 3
typedef struct {
	int* List;
	int length;//��ǰ����
	int List_len;//������ܳ��ȣ�
}Sqlist;
void InitList(Sqlist* L) {
	L->List = (int*)malloc(List_size * sizeof(int));
	if (L->List == NULL) {
		printf("��̬�ڴ����ʧ�ܣ�");
		exit(-1);
	}

	L->length = 0;
	L->List_len = List_size;
}
void Insert_List(Sqlist* L, int pos, int data) {
	if (pos<1 || pos>L->length + 1) {
		printf("������Ԫ�ص�λ�ò��Ϸ���");
		exit(-1);
	}
	if (L->length >= L->List_len) {
		printf("�ڴ�������Ҫ���ݣ�\n");
		L->List = (int*)realloc(L->List, (L->List_len + ListIncrement) * sizeof(int));
		if (L->List == NULL) {
			printf("��̬�ڴ����ʧ�ܣ�");
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
		printf("��ɾ��Ԫ�ص�λ�ò��Ϸ���");
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
		printf("���޸ĵ�Ԫ��λ�ò��Ϸ���");
		exit(-1);
	}
	L->List[pos - 1] = val;
}
int Getval(Sqlist L, int pos) {
	if (pos<1 || pos>L.length + 1) {
		printf("�����ҵ�Ԫ��λ�ò��Ϸ���");
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
		printf("�������%d��Ԫ�أ�", i + 1);
		scanf("%d", &data);
		Insert_List(&L, 1, data);
	}
	printf("��������������Ԫ��λ��:");
	scanf("%d", &pos);
	printf("��������������ֵ��");
	scanf("%d", &val);
	Insert_List(&L, pos, val);
	/*printf("%d\n", L.length);
	printf("%d\n", L.List_len);*/
	/*printf("%d\n", L.List[1]);*/
	/*printf("%p\n", &L.List[1]);*/
	printf("�����˳���Ϊ:");
	List_traverse(&L);
	printf("����������ɾ����Ԫ��λ��:");
	scanf("%d", &pos);
	List_delete(&L, pos);
	printf("ɾ����%d��λ�õ�Ԫ�غ�˳���Ϊ��", pos);
	List_traverse(&L);
	List_Sort(&L);
	printf("�����˳���Ϊ:");
	List_traverse(&L);
	printf("����������Ҫ�޸ĵ�Ԫ��λ��:");
	scanf("%d", &pos);
	printf("�����������޸ĵ�ֵ��");
	scanf("%d", &val);
	List_modify(&L, pos, val);//�޸ĵ�һ��Ԫ�ص�ֵΪ0��
	printf("�޸ĺ�˳���Ϊ:");
	List_traverse(&L);
	printf("����������Ҫ��ȡԪ�ص�λ�ã�");
	scanf("%d", &pos);
	printf("˳����%d��Ԫ��Ϊ��%d\n", pos, Getval(L, pos));
	printf("����������Ҫ���ҵ�Ԫ�أ�");
	scanf("%d", &val);
	if (Locate(L, val) == 0) {
		printf("˳�����û������Ҫ���ҵ�ֵ��\n");
	}
	else printf("��Ԫ�ص��±�Ϊ��%d\n", Locate(L, val));

}