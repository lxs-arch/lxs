#include<stdio.h>
#include<math.h>
int main() {
    int x, i = 0;
    scanf("%d", &x);
    int y = 0;
    while (x > 0) {
        if (x % 2 == 1) y += pow(10, i);
        x /= 2;
        i++;
    }
    printf("%d", y);
    return 0;
}