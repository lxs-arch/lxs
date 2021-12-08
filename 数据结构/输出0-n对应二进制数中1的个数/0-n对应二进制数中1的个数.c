int Count(int x) {
    int n = 0;
    while (x > 0) {
        if (x % 2 == 1) n++;
        x /= 2;
    }
    return n;
}
int* countBits(int n, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * (n + 1));
    *returnSize = n + 1;
    int i;
    for (i = 0; i <= n; i++) {

        ret[i] = Count(i);
    }
    return ret;
}