#include <stdio.h>

int main() {

    // char 'a' = 97, 'z' = 122, 'A' = 65, 'Z' = 90, 空白是32, 換行是10
    int n = 0, keyArr[100] = {};
    char key = 0, message = 0;
    scanf("%d", &n);

    scanf("%c", &key);  //讓compiler進到下一行

    // 記錄偏移量
    for (int i = 0; i < n ; i++) {
        scanf("%c", &key);
        if (key == '\n' || key == '\0')
            continue;
        keyArr[i] = (int) key - (int) 'a';
    }

    scanf("%c", &key);  //讓compiler進到下一行

    for (int i = 0; message != '\n'; i++) {
        if (i == n)
            i = 0;
        scanf("%c", &message);
        if (message == '\n')
            break;
        if (((int) message) >= 'A' && (int) message <= 'Z') {
            printf("%c", message + keyArr[i] > 90 ? message - 26 + keyArr[i] : message + keyArr[i]);
        } else if ((int) message >= 'a' && (int) message <= 'z')
            printf("%c", message + keyArr[i] > 122 ? message - 26 + keyArr[i] : message + keyArr[i]);
        else {
            printf("%c", message);
            i--;
        }
    }

    return 0;
}