#include <stdio.h>

void operationR();
void operationV();
void operationH();
void operationC();
void operationPrint();
int m = 0, n = 0, image[101][101] = {};
int main() {
    int operationTimes = 0;
    char operation = 0;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &image[i][j]);
        }
    }
    scanf("%d", &operationTimes);
    for (int i = 0; i < operationTimes; i++) {
        scanf("%c", &operation); // 讀入個換行字符或者空白
        scanf("%c", &operation); // 這個才是真正的讀入
        if (operation == 'r')
            operationR();
        else if (operation == 'v')
            operationV();
        else if (operation == 'h')
            operationH();
        else if (operation == 'c')
            operationC();
        else if (operation == 'p')
            operationPrint();
    }
    return 0;
}

void operationR() {
    char way = 0;
    int times = 0;
    int tmp[101][101] = {}, tmpDimension = 0;
    scanf("%c", &way);
    scanf("%c", &way);
    scanf("%d", &times);
    if ((times % 4 == 1 && way == 'r') || (times % 4 == 3 && way == 'l'))  {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tmp[i][j] = image[m - j - 1][i];
            }
        }
        tmpDimension = m;
        m = n;
        n = tmpDimension;
    } else if ((times % 4 == 2 && way == 'r') || (times % 4 == 2 && way == 'l')) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp[i][j] = image[m - i - 1][n - j - 1];
            }
        }
    } else if ((times % 4 == 3 && way == 'r') || (times % 4 == 1 && way == 'l')) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tmp[i][j] = image[j][n - i - 1];
            }
        }
        tmpDimension = m;
        m = n;
        n = tmpDimension;
    } else if ((times % 4 == 0 && way == 'r') || (times % 4 == 0 && way == 'l')) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp[i][j] = image[i][j];
            }
        }
    }
    for (int i = 0; i < 101; i++) {         // 更新圖片，把暫存的陣列存入
        for (int j = 0; j < 101; j++) {
            image[i][j] = tmp[i][j];
        }
    }
}
void operationV() {
    int tmp[101][101] = {};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = image[m - i - 1][j];
        }
    }
    for (int i = 0; i < 101; i++) {         // 更新圖片，把暫存的陣列存入
        for (int j = 0; j < 101; j++) {
            image[i][j] = tmp[i][j];
        }
    }
}
void operationH() {
    int tmp[101][101] = {};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = image[i][n - j - 1];
        }
    }
    for (int i = 0; i < 101; i++) {         // 更新圖片，把暫存的陣列存入
        for (int j = 0; j < 101; j++) {
            image[i][j] = tmp[i][j];
        }
    }
}
void operationC() {
    int left = 0, right = 0, up = 0, down = 0, tmp[101][101] = {};
    scanf("%d", &left);
    scanf("%d", &right);
    scanf("%d", &up);
    scanf("%d", &down);
    for (int i = up - 1, i0 = 0; i < down; i++, i0++) {
        for (int j = left - 1, j0 = 0; j < right; j++, j0++) {
            tmp[i0][j0] = image[i][j];
        }
    }
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            image[i][j] = tmp[i][j];
        }
    }
    m = down - up + 1;
    n = right - left + 1;
}
void operationPrint() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}