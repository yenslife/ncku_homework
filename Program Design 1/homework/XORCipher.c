#include <stdio.h>

int main(void) {
    char key[1000] = "";
    char data[10000] = "";
    char output[10000] = "";
    int dataNum = 0, keyNum = 0;
    for (int i = 0;; i++) {
        key[i] = getchar();
        if (key[i] == '\n')
            break;
        keyNum++;
    }
    for (int i = 0;; i++) {
        data[i] = getchar();
        if (data[i] == '\n')
            break;
        dataNum++;
    }
    // printf("keyNum = %d, dataNum = %d\n", keyNum, dataNum);
    for (int i = 0; i < dataNum; i++) {
        output[i] = data[i] ^ key[i % keyNum];
        printf("%c", output[i]);
    }
}
