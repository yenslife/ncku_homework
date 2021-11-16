#include <stdio.h>
#include <stdlib.h>

int cmp(const int *a, const int *b) {
    return *a > *b ? 1 : -1;
}

int main() {
    int n1 = 0, n2 = 0, n = 0;
    scanf("%d %d", &n1, &n2);
    n = n1 + n2;
    int arr[10000] = {};
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), cmp);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
