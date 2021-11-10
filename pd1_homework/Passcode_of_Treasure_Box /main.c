#include <stdio.h>

int passcode(int n) {
    if (n % 2 == 0) {
        return passcode(n/2);
    } else if (n == 0 || n ==1)
        return 1;
    else if (n % 2 != 0) {
        return passcode(n + 1) + passcode(n - 1);
    }
}
int main() {
    int n = 0;
    scanf("%d", &n);
    printf("%d", passcode(n));
    return 0;
}
