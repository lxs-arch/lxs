/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 求出a、b的最大公约数。
 * @param a int
 * @param b int
 * @return int
 */
int gcd(int a, int b) {
    if (b > a) {
        int t = a;
        a = b;
        b = t;
    }
    while (a - b) {
        a = a - b;
        if (b > a) {
            int t = a;
            a = b;
            b = t;
        }
    }
    return a;
}