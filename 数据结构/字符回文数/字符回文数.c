/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * @param str string字符串 待判断的字符串
 * @return bool布尔型
 */
bool judge(char* str) {
    // write code here
    if (str == NULL) {
        return false;
    }
    int n = strlen(str);
    int i;
    for (i = 0; i < n / 2; i++) {
        if (str[i] != str[n - 1 - i]) {
            return false;
        }
    }
    return true;
}