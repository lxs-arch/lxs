#define _CRT_SECURE_NO_WARNINGS 1
#include"sqlist.h"
void TestList1() {
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 9);
	SeqListPrint(&s);
	SeqListPopBack(&s, 8);
	SeqListPopBack(&s, 9);
	SeqListPrint(&s);
	SeqListPushFront(&s,10);
	SeqListPushFront(&s, 20);
	SeqListPushFront(&s, 30);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListDestroy(&s);
}
int main() {
	TestList1();

	return 0;
}