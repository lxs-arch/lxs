#define _CRT_SECURE_NO_WARNINGS 1
//ʵ��strcpy����
#include<stdio.h>
#include<string.h>
#include<assert.h>
char* my_strcpy(char* str1, char* str2)
{
    assert(str2);//�ж�Դ��ַ�Ƿ�Ϊ�գ�
    char* cur = str1;
    while (*str2 != '\0')
    {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
    return cur;
}
int main()
{
    char str1[10];
    char str2[10] = "China";
    printf("%s\n", my_strcpy(str1, str2));
    return 0;
}