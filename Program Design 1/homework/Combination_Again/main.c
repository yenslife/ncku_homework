#include <stdio.h>

int C(int n, int m) {
    return m == 0 || m == n ? 1 : C(n - 1, m - 1) + C(n - 1, m);
}
int main() {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    printf("%d", C(n,m));
    return 0;
}