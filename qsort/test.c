#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int cmp_float(const void*e1,const void*e2) {
    return (*(int*)e1 - *(int*)e2);
}
void test() {
    float f[] = { 2.0,3.0,5.0,1.0,4.0,8.0,9.0 };
    int sz = sizeof(f) / sizeof(f[0]);
    qsort(f, sz, sizeof(f[0]), cmp_float);
    for (int j = 0; j < sz; j++) {
        printf("%f ", f[j]);
    }

}
int main() {
    test();
    return 0;
}