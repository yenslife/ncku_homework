#include <stdio.h>
// 'a' = 97 'z' = 122 'A' = 65 'Z' = 90
//1 <= N <= 30
//1 <= n <= 16
int main() {
    int N = 0, n = 0, n_transfer = 0, count = 0;
    char c = '0', trashCan = '0', name[] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                                            '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                                            '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                                            '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                                            '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                                            '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                                            '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                                            '0'};
    scanf("%d", &N);
    scanf("%d", &n_transfer);
    scanf("%c", &trashCan);   //掃進空白以便掃進轉學生名字
    for (int i = 0; i < n_transfer; i++) {
        scanf("%c", &c);
        if (c >='A' && c <= 'Z')
            c += 32;
        name[i] = c;
    }
    // 看他大於幾個
    for (int i = 0; i < N; i++) {
        scanf("%d", &n);
        scanf("%c", &trashCan);
        for (int j = 0; j < n; j++) {
            scanf("%c", &c);
            if (c >='A' && c <= 'Z')
                c += 32;
            if (name[j] == c);
            else if (name[j] == '0') {
                while (1) {
                    scanf("%c", &c);
                    if (c == '\n')
                        break;
                }
                break;
            } else if (name[j] < c) {
                while (1) {
                    scanf("%c", &c);
                    if (c == '\n')
                        break;
                }
                break;
            } else if (name[j] > c) {
                count++;
                while (1) {
                    scanf("%c", &c);
                    if (c == '\n')
                        break;
                }
                break;
            }
        }
    }
    printf("%d", count++);
    return 0;
}
