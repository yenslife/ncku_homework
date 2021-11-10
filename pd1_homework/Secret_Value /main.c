#include <stdio.h>

#define MODULUS 10007

int getSecret(int n);

int gcd(int a, int b);

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", getSecret(n));
    return 0;
}

int power(int x, int y) {
    int i = 1;
    while (y > 0) {
        i *= x;
        y--;
    }
    return i;
}

long long int sum = 0;
int getSecret(int n) {
    int a = 0, b = 0, digit = 0, a_digit = 0, b_digit = 0;
    for (int i = n; i > 0; digit++) {                      //算n共幾位數
        i /= 10;
    }
    a_digit = digit / 2;                                   //前半部位數
    b_digit = digit - a_digit;                             //後半部位數
    a = n / power(10, b_digit);                         //前半部數字
    b = n - a * power(10, b_digit);                     //後半部數字
    if (sum == 0)
        sum = n;                                           //將第一個n加入sum
    if (n / 10 == 0)
        return n;                                          //若n為個位數
    if (gcd(a, b) / 10 == 0) {                             //若gcd為一位數則輸出總和
        sum += gcd(a, b);
        return sum % MODULUS;
    } else if (gcd(a, b) / 10 != 0) {                      //若gcd不為一位數則繼續執行函示
        sum += gcd(a, b);
        return getSecret(gcd(a, b)) % MODULUS;
    }
}

int gcd(int a, int b) {
    int i = 0;
    if (b > a && b % a != 0) {
        i = b % a;
        b = a;
        a = i;
    }
    if (b % a == 0)
        return a;
    if (a > b && a % b != 0) {
        i = a % b;
        a = b;
        b = i;
    }
    if (a % b == 0)
        return b;
    return gcd(a, b);
}