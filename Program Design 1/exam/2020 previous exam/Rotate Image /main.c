#include <stdio.h>

int main() {
    //輸入陣列
    int angel = 0, m = 0, n = 0, a[100][100];
    scanf("%d %d %d", &angel, &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    //旋轉
    if (angel == 90) {
        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                printf("%d ", a[j][i]);
            }
            printf("\n");
        }
    } else if (angel == 180) {
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n -1; j >= 0; j--) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    } else if (angel == 270) {
        for (int j = n - 1; j >= 0; j--) {
            for (int i = 0; i < m; i++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
