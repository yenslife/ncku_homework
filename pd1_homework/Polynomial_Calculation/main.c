#include <stdio.h>

int main() {
    float x, x1, x2, x3, x4;
    scanf("%f", &x);
    //𝟕𝐱⁴ - 𝟖𝐱³ - 𝐱² + 𝟔𝐱 - 𝟐𝟐
    x1 = 7*x*x*x*x;
    x2 = -8*x*x*x;
    x3 = -1*x*x;
    x4 = 6*x;
    x = x1 + x2 + x3 + x4 -22;
    printf("%.1f", x);
    return 0;
}
