#include <math.h>
#include <stdint.h>
#include <stdio.h>

int bingo(unsigned char[]);

int main() {
    unsigned char num[8];
    for (int i = 0; i < 8; ++i) {
        scanf("%hhu", &num[i]);
    }
    printf("%d\n", bingo(num));
}

// use bitwise operation to right shift these bit 8 times and check if they
// match 00000001 for example 2 >> 00000000

int bingo(unsigned char num[]) {
    int sum = 0;
    int tmp[8];
    for (int i = 0; i < 8; i++) {
        if (num[i] == 255)  // 255 為那一排都是一
            sum++;
    }
    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            tmp[j] = num[j] >> i;
            tmp[j] = tmp[j] & 1;
        }
        if ((tmp[0] & tmp[1] & tmp[2] & tmp[3] & tmp[4] & tmp[5] & tmp[6] &
             tmp[7]) == 1) {
            sum++;
        }
    }
    //檢查斜的
    for (int i = 0, j = 0, k = 7; i < 8; i++, j++, k--) {
        tmp[i] = num[i] >> k;
        tmp[i] = tmp[i] & 1;
    }
    if ((tmp[0] & tmp[1] & tmp[2] & tmp[3] & tmp[4] & tmp[5] & tmp[6] &
         tmp[7]) == 1)
        sum++;
    for (int i = 0, j = 0, k = 7; i < 8; i++, j++, k--) {
        tmp[i] = num[i] << k;
        tmp[i] = tmp[i] & 128;
    }
    if ((tmp[0] & tmp[1] & tmp[2] & tmp[3] & tmp[4] & tmp[5] & tmp[6] &
         tmp[7]) == 128)
        sum++;
    // 1 3 3 5 9 17 33 65 129
    return sum;
}