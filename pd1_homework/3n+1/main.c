#include <stdio.h>

int main() {
    int s1, L = 1, M;
    scanf("%d", &s1);
    M = s1;
    for (; s1 != 1; L++) {
        if (s1 % 2 == 0) {
            s1 = s1 / 2;
        } else {
            s1 = s1 * 3 + 1;
        }
        if (M < s1) {
            M = s1;
        }
    }
    if (M < s1) {
        M = s1;
    }
    printf("%d %d\n", L, M);
    return 0;
}
