#include <stdio.h>
#include <stdbool.h>

int main() {
    int n = 0, rings = 0;
    scanf("%d", &n);
    int a[n], b[n];
    bool check[500] = {false};
    // 放進陣列
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    //數量
    for (int i = 0; i < n; i++) {
        if (check[i] == false) {
            while (a[i] != i) {
                check[a[i]] = true;
                a[i] = a[a[i]];
            }
            rings++;
        }
    }
    printf("%d rings\n", rings);
    //箭頭
    bool check1[500] = {false};

    for (int i = 0; i < n; i++) {
        if (check1[i] == false) {
            if (check1[i] == false) {
                printf("%d -> ", i);
            }
            while (b[i] != i) {
                check1[b[i]] = true;
                printf("%d -> ", b[i]);
                b[i] = b[b[i]];
            }
            printf("%d\n", i);
        }
    }
    return 0;
}
