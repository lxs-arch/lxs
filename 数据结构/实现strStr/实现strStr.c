int strStr(char* haystack, char* needle) {
    int p = 0, q = 0;
    int m = strlen(haystack), n = strlen(needle);
    if (n == 0) {
        return 0;
    }
    while (q < n && p < m) {
        if (haystack[p] == needle[q]) {
            p++;
            q++;
        }
        else {
            p = p - q + 1;
            q = 0;
        }
    }
    if (q == n) {
        return p - q;
    }
    else return -1;
}
//