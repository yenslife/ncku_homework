#include<stdio.h>

int *poly(int*, int*, int*);
//𝐱³ + y² + z
int main() {
    int a, b, c;
    int *A, *B, *C;
    scanf("%d %d %d", &a, &b, &c);
    A = &a;
    B = &b;
    C = &c;
    if (a < 0) A = NULL;
    if (b < 0) B = NULL;
    if (c < 0) C = NULL;

    int *result = poly(A, B, C);
    printf("%d", *result);
    return 0;
}

int *poly(int* A, int* B, int* C) {
    static int sum, zero = 0;
    if (A == NULL) A = &zero;
    if (B == NULL) B = &zero;
    if (C == NULL) C = &zero;
    sum = *A * *A * *A + *B * *B + *C;
    return &sum;
}