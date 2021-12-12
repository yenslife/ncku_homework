#include <stdio.h>

void addition(long long sum);
int main(void) {
    long long tmp = 0, counter = 0, evenSum = 0, oddSum = 0;
    while(scanf("%1llx", &tmp) != EOF) {
        if (counter % 2 == 0) {
            evenSum += tmp;
        } else if (counter % 2 == 1) {
            oddSum += tmp;
        }
        counter++;
    }
    addition(oddSum);
    addition(evenSum);
    return 0;
}

void addition(long long sum) {
    long long evenSum = 0, oddSum = 0, tmpSum = sum, digit = 0, a[10001] = {};
    if (sum / 16 == 0) {
        printf("%llx", sum);
        return;
    }
    for(int i = 0;; i++) {
        if (tmpSum == 0)
            break;
        tmpSum/=16;
        digit++;
    }
    tmpSum = sum;
    for(int i = digit - 1;; i--) {
        if (tmpSum == 0)
            break;
        a[i] += tmpSum % 16;
        tmpSum/=16;
    }
    tmpSum = sum;
    while (0 < digit) {
        if (digit % 2 == 0) {
            oddSum += a[digit - 1];
            digit--;
        }
        if (digit % 2 == 1) {
            evenSum += a[digit - 1];
            digit--;
        }
    }
    addition(oddSum);
    addition(evenSum);
}