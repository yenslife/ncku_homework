#include <stdio.h>

int main() {
    double r = 0, people = 1;
    int n = 0;
    scanf("%lf %d", &r, &n);
    for (int i = 0; i < n; i++) {
        people*=r;
    }
    n = (int)people;
    printf("%d", n);
    return 0;
}
