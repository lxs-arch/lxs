#define _CRT_SECURE_NO_WARNINGS 1
#include"sqlist.h"
Status visit(ElemType c)
{
    printf("%d ", c);
    return OK;
}
/* 初始化顺序线性表 */
Status InitList(SqList* L)
{
    L->length = 0;
    return OK;
}
/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty(SqList L)
{
    if (L.length == 0)
        return TRUE;
    else
        return FALSE;
}
/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(SqList* L)
{
    L->length = 0;
    return OK;
}
/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(SqList L)
{
    return L.length;
}
/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 */
Status GetElem(SqList L, int i, ElemType* e)
{
    if (L.length == 0 || i<1 || i>L.length)
        return ERROR;
    *e = L.data[i - 1];

    return OK;
}
/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int LocateElem(SqList L, ElemType e)
{
    int i;
    if (L.length == 0)
        return 0;
    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            break;
    }
    if (i >= L.length)
        return 0;

    return i + 1;
}
/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(SqList* L, int i, ElemType e)
{
    int k;
    if (L->length == MAXSIZE)  /* 顺序线性表已经满 */
        return ERROR;
    if (i<1 || i>L->length + 1)/* 当i比第一位置小或者比最后一位置后一位置还要大时 */
        return ERROR;

    if (i <= L->length)        /* 若插入数据位置不在表尾 */
    {
        for (k = L->length - 1; k >= i - 1; k--)  /* 将要插入位置之后的数据元素向后移动一位 */
            L->data[k + 1] = L->data[k];
    }
    L->data[i - 1] = e;          /* 将新元素插入 */
    L->length++;

    return OK;
}
/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(SqList* L, int i, ElemType* e)
{
    int k;
    if (L->length == 0)               /* 线性表为空 */
        return ERROR;
    if (i<1 || i>L->length)         /* 删除位置不正确 */
        return ERROR;
    *e = L->data[i - 1];
    if (i < L->length)                /* 如果删除不是最后位置 */
    {
        for (k = i; k < L->length; k++)/* 将删除位置后继元素前移 */
            L->data[k - 1] = L->data[k];
    }
    L->length--;
    return OK;
}
/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(SqList L)
{
    int i;
    for (i = 0; i < L.length; i++)
        visit(L.data[i]);
    printf("\n");
    return OK;
}
/*将所有的在线性表Lb中但不在La中的数据元素插入到La中*/
void unionL(SqList* La, SqList Lb)
{
    int La_len, Lb_len, i;
    ElemType e;                        /*声明与La和Lb相同的数据元素e*/
    La_len = ListLength(*La);            /*求线性表的长度 */
    Lb_len = ListLength(Lb);
    for (i = 1; i <= Lb_len; i++)
    {
        GetElem(Lb, i, &e);              /*取Lb中第i个数据元素赋给e*/
        if (!LocateElem(*La, e))        /*La中不存在和e相同数据元素*/
            ListInsert(La, ++La_len, e); /*插入*/
    }
}
