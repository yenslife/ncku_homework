#include <stdio.h>

int main() {
    // 'a' = 97 'z' = 122 'A' = 65 'Z' = 90
    int n = 0;
    char ad = '0', trashCan = 0, c = 0;
    scanf("%d", &n);
    scanf("%c", &trashCan);  // skip掉空白
    scanf("%c", &ad);
    scanf("%c", &trashCan);
    n %= 26;

    if (ad == 'a') {        //處理a情況
        while (1) {
            if (c == '\n')
                break;
            scanf("%c", &c);
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) { //如果他是英文字母
                if ((c + n > 'z') || (c + n > 'Z' && (c >= 'A' && c <= 'Z'))) {
                    printf("%c", c + n - 26);
                } else {
                    printf("%c", c + n);
                }
                n++;
                n %= 26;
            } else
                printf("%c", c);
        }
    } else if (ad == 'd') {
        while (1) {
            if (c == '\n')
                break;
            scanf("%c", &c);
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) { //如果他是英文字母
                if ((c + n < 'A') || (c + n < 'a' && (c >= 'a' && c <= 'z'))) {
                    printf("%c", c + n + 26);
                } else {
                    printf("%c", c + n);
                }
                n--;
                n %= 26;
            } else
                printf("%c", c);
        }
    }
    return 0;
}
