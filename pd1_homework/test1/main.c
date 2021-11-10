#include <stdio.h>
#include <stdlib.h>

int cmp(int *a, int *b) {
    return *a - *b;
}

int main() {
    int a[5] = {837, 5, 13, 83, 6};
    qsort(a, 5, sizeof(int), cmp);
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}