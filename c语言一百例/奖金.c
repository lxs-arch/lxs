#include<stdio.h>
int main()
{
    float i, sum = 0, a, b, c, d, e, f;
    scanf("%f", &i);
    a = 10 * 0.1;
    b = 10 * 0.075 + a;
    c = 20 * 0.05 + b;
    d = 20 * 0.03 + c;
    e = 20 * 0.15 + d;

    if (i <= 10) {
        a = i * 0.1;
        sum = a;
    }
    else if (10 < i && i <= 20) {
        b = (i - 10) * 0.075 + a;
        sum = b;
    }
    else if (20 < i && i <= 40) {
        c = (i - 20) * 0.05 + b;
        sum = c;
    }
    else if (i > 40 && i <= 60) {
        d = (i - 40) * 0.03 + c;
        sum = d;
    }
    else if (i > 60 && i <= 100) {
        e = (i - 60) * 0.15 + d;
        sum = e;
    }
    else if (i > 100) {
        f = (i - 100) * 0.01 + e;
        sum = f;
    }
    printf("%f\n", sum);
    return 0;
}
