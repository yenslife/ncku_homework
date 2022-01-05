#include <stdio.h>
int traversalMode = 0, node = 1, number = 0;
void binary(int a[], int node);

int main() {
    int a[5000] = {};
    scanf("%d", &traversalMode);
    scanf("%d", &number);
    for (int i = 1; i < number + 1; i++) {
        scanf("%d", &a[i]);
    }
    binary(a, node);
    return 0;
}

void binary(int a[], int node) {
    if (traversalMode == 0) {
        if (node > number) return;
        printf("%d ", a[node]);
        binary(a, node * 2);
        binary(a, node * 2 +1);
    } else if (traversalMode == 1) {
        if (node > number) return;
        binary(a, node * 2);
        printf("%d ", a[node]);
        binary(a, node * 2 + 1);
    } else if (traversalMode == 2) {
        if (node > number) return;
        binary(a, node * 2);
        binary(a, node * 2 + 1);
        printf("%d ", a[node]);
    }
}