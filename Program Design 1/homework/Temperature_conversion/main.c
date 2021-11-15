#include <stdio.h>

int main() {
    float C, F;
    //Fahrenheit = Celsius *9/5 + 32
    // / 5 + 32
    scanf("%f", &C);
    F = C * 9 / 5 + 32;
    printf("%.2f", F);
    return 0;
}
