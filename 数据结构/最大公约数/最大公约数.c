/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 * ���a��b�����Լ����
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