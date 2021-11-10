#include <stdio.h>

int main() {
    int n = 0, s = 0, check = 1000000007,k = 0,sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &s);
        if (s == 6) {
            long long num = 0, numk = 0, sum6 = 0;
            int digit = 0;
            scanf("%lld", &numk);
            num = numk;
            for (; numk > 0; digit++) {
                numk = numk / 10;
            }
            for (; digit > 0; digit--) {
                long long target = num;
                for (int i = digit - 1; i > 0; i--) {
                    target /= 10;
                }
                long long index = target;
                if (target == num) {
                    target = num % (10 * digit);
                } else if (target == 10) {
                    target = 0;
                } else {
                    for (int power = digit - 1; power > 0; power--) {
                        target *= 6;
                    }
                }
                sum6 = (sum6 + target)%check;
                for (int j = 1; j < digit; ++j) {
                    index *= 10;
                }
                num -= index;
            }
            sum = (sum + sum6%check)%check;
        }
        if (s == 8) {
            scanf("%o", &k);
            sum = (sum + k%check)%check;
        }
        if (s == 10) {
            scanf("%d", &k);
            sum = (sum + k%check)%check;
        }
        if (s == 16) {
            scanf("%x", &k);
            sum = (sum + k%check)%check;
        }
    }
    sum = sum % check;
    printf("%d", sum);
    return 0;
    //到底為什麼不行啊啊啊啊啊啊啊qwq
}