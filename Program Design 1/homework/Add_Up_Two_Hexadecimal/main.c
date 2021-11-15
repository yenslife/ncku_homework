#include <stdio.h>

int main() {
    unsigned int a, b, sum;
    scanf("%x %x", &a, &b);
    sum = a + b;
    if (sum > 0xFFFF) {
        printf("OVERFLOW!");
    } else {
        printf("%d\n", (int) sum);
    }
    printf("%d", sizeof(long double));
    return 0;
}
