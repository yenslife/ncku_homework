#include <stdio.h>

int main() {
    int num = 0, k = 0, mark = 0;
    char c = 'c';
    scanf("%d\n", &num);
    mark = num;
    num = ((num >= 0) ? num : -(num));
    k = num - (num / 26) * 26;
    if (mark >= 0) {
        for (; c != 10;) {
            c = getchar();
            if (65 <= c && c <= 90) {
                if ((c + k) > 90) {
                    c = c - 26 + k;
                    printf("%c", c);
                } else {
                    c = c + k;
                    printf("%c", c);
                }
            } else if (97 <= c && c <= 122) {
                if ((c + k) > 122) {
                    c = c - 26 + k;
                    printf("%c", c);
                } else {
                    c = c + k;
                    printf("%c", c);
                }
            } else {
                printf("%c", c);
            }
        }
    } else {
        for (; c != 10;) {
            c = getchar();
            if (65 <= c && c <= 90) {
                if ((c - k) < 65) {
                    c = c + 26 - k;
                    printf("%c", c);
                } else {
                    c = c - k;
                    printf("%c", c);
                }
            } else if (97 <= c && c <= 122) {
                if ((c - k) < 97) {
                    c = c + 26 - k;
                    printf("%c", c);
                } else {
                    c = c - k;
                    printf("%c", c);
                }
            } else {
                printf("%c", c);
            }
        }
    }
    return 0;
}
