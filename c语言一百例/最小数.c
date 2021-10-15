#inclu#include <stdio.h>

int main(void)
{
    int x, y, z, min;
    scanf("%d %d %d", &x, &y, &z);
    min = (x < y ? x : y) < z ? (x < y ? x : y) : z;
    printf("%d", min);
    return 0;
}