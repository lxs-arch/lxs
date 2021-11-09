#include <stdio.h>
int main()
{
    int h = 0;
    int m = 0;
    int k = 0;
    scanf("%d:%d %d", &h, &m, &k);
    h = ((m + k) / 60 + h) % 24;
    m = (m + k) % 60;
    printf("%02d:%02d\n", h, m);
    return 0;
}
//输入现在的时刻以及要睡的时长k（单位：minute），中间用空格分开。

//输入格式：hour:minute k(如hour或minute的值为1，输入为1，而不是01)