#include <stdio.h>

int main() {
    int n = 0, a[50][50] = {0};
    scanf("%d", &n);
    a[0][n / 2] = 1;
    for (int num = 2, x = 0, y = n / 2; num <= n * n; num++) {
        x--;
        y++;
        if (a[x][y] != 0 && x >= 0 && y <= n - 1) {          //處理如果右上方有數字了（會很長）
            x += 2;
            y -= 1;
            a[x][y] = num;
        } else if (x < 0 && y > n - 1) {               //處理三種超出邊界的情況
            if (a[n - 1][0] == 0) {
                x = n - 1;
                y = 0;
                a[x][y] = num;
            } else {
                x = 1;
                y = n - 1;
                a[x][y] = num;
            }
        } else if (x < 0) {
            x = n - 1;
            a[x][y] = num;
        } else if (y > n - 1) {
            y = 0;
            a[x][y] = num;
        } else {
            a[x][y] = num;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
