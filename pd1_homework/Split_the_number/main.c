#include <stdio.h>

int main() {
    int x, y, z;
    scanf("%d", &x);
    if (x < 10) {
        printf("0 0 %d\n", x);
    } else if (10 <= x && x < 100) {
        y = x / 10;
        z = x - y * 10;
        printf("0 %d %d", y, z);
    } else {
        y = x / 100;
        z = (x - y * 100) / 10;
        x = x - 100 * y - 10 * z;
        printf("%d %d %d", y, z, x);
    }
    return 0;
}
