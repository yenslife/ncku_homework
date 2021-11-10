#include <stdio.h>

/*int main() {
    int m = 0, n = 0, m1 = 0, n1 = 0, mn = 0;
    unsigned long long int n_factorial = 1, m_factorial = 1, mn_factorial = 1, c = 0;
    scanf("%d%d", &m, &n);
    if (m == 0) {
        m_factorial = 1;
    } else {
        m1 = m;
        for (int i = 0; i < m; i++, m1--) {
            m_factorial = m_factorial * m1;
        }
    }
    if (n == 0) {
        n_factorial = 1;
    } else {
        n1 = n;
        for (int i = 0; i < n; i++, n1--) {
            n_factorial = n_factorial * n1;
        }
    }
    mn = m - n;
    if (mn == 0) {
        mn_factorial = 1;
    } else {
        for (int i = 0; i < mn; i++, mn--) {
            mn_factorial = mn_factorial * mn;
        }
    }
    c = m_factorial / (n_factorial * mn_factorial);
    printf("%llu", c);
    return 0;
}*/
int main() {
    int m = 0, n = 0, mn = 0, m1 = 0;
    unsigned long long int numerator = 1, denominator = 1, c = 0;
    //分子:numerator 分母:denominator
    scanf("%d%d", &m, &n);
    mn = m - n;
    m1 = m;
    if (m == 0) {
        numerator = 1;
    } else {
        if ((n + 1) <= (m - n)) {
            for (; m1 >= (m - n + 1); m1--) {
                numerator *= m1;
                //puts("1");
            }
        } else {
            for (; m1 >= (n + 1); m1--) {
                numerator *= m1;
                //puts("2");
            }
        }
    }
    if (mn == 0) {
        denominator = 1;
    } else {
        if ((n + 1) <= (m - n)) {
            for (int i = 1;i <= n;i++){
                denominator*=i;
                //puts("3");
            }
        } else {
            for (int i = 1; i <= mn;i++) {
                denominator = denominator * i;
                //puts("4");
            }
        }
    }
    c = numerator / denominator;
    printf("%llu", c);
    return 0;
}