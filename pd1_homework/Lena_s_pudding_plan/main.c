#include <stdio.h>

int main() {
    int i1, i2, i3, sum, eachDay, left;
    scanf("%d%d%d", &i1, &i2, &i3);
    sum = i1 + i2 + i3;
    eachDay = sum / 7;
    left = sum - eachDay * 7;
    printf("%d %d", eachDay, left);
    return 0;
}
