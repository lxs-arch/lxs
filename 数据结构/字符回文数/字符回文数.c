/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 * @param str string�ַ��� ���жϵ��ַ���
 * @return bool������
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