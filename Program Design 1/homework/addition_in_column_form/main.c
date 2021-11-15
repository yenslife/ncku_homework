#include <stdio.h>

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%6.4d\n", x);
    printf("+)%.4d\n", y);
    printf("------\n");
    printf("%.6d", x+y);
    return 0;
}
