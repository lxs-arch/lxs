#define _CRT_SECURE_NO_WARNINGS 1
//把参数插入到字符串中。
#define PRINTF(x) printf("the value of "#x" is %d",x);
#include<stdio.h>
int main()
{
    int x;
    printf("请输入x的值：");
    scanf("%d", &x);
    PRINTF(x);
    return 0;
}