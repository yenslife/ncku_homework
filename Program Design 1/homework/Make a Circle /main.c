#include <stdio.h>

int main() {
    int radius;
    float area, length;
    scanf("%d", &radius);
    area = radius * radius * 3.14f;
    length = 2 * radius * 3.14f;
    printf("%.2f %.2f", area, length);
    return 0;
}
