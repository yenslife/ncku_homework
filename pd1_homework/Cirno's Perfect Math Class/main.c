#include <stdio.h>

int main() {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    printf("%.4d %.4d %.4d", A, A-B+C, A-B+C-D);
    return 0;
}
