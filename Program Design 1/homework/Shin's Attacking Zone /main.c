#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 1024

void convert_to_polar(int *coords, int N);

int main()
{
    int N, coords[MAX_N + 1][2];
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d%d", &coords[i][0], &coords[i][1]);


    convert_to_polar((int *) coords, N);

    return 0;
}
#define PI 3.14159265;
void convert_to_polar(int *coords, int N) {
    double val, degree = 0, x, y, length = 0;
    val = 180 / PI;
    for (int i = 0; i < N; i++) {
        x = *(coords + i * 2);
        y = *(coords + i * 2 + 1);
        //printf("x = %d, y = %d, i = %d\n", *(coords + i * 2), *(coords + i * 2 + 1), i);
        if (x >= 0 && y >= 0) {
            degree = atan(y / x) * val;
            length = sqrt(x * x + y * y);
            printf("%.2f %.2f\n", degree, length);
        } else if (x < 0 && y >= 0) {
            x *= (-1);
            degree = 180 - atan(y / x) * val;
            length = sqrt(x * x + y * y);
            printf("%.2f %.2f\n", degree, length);
        } else if (x < 0 && y < 0) {
            x *= (-1);
            y *= (-1);
            degree = 180 + atan(y / x) * val;
            length = sqrt(x * x + y * y);
            printf("%.2f %.2f\n", degree, length);
        } else if (x >= 0 && y < 0) {
            y *= (-1);
            degree = 360 - atan(y / x) * val;
            length = sqrt(x * x + y * y);
            printf("%.2f %.2f\n", degree, length);
        }
    }
}