#include <stdio.h>
#include <math.h>

int main() {
    int mode = 0;
    double volume = 0;
    scanf("%d", &mode);
    if (mode == 1) {
        double length;
        scanf("%lf", &length);
        volume = pow(length, 3);
    } else if (mode == 2){
        double a, b, c;
        scanf("%lf %lf %lf", &a, &b, &c);
        volume = a * b * c;
    } else if (mode == 3){
        double radius, height, pi = 3.14;
        scanf("%lf %lf", &radius, &height);
        volume = pi * height * radius * radius;
    } else if (mode == 4) {
        double length;
        scanf("%lf", &length);
        volume = sqrt(2) / 12 * pow(length, 3);
    }
    printf("%.2lf", volume);
    return 0;
}
