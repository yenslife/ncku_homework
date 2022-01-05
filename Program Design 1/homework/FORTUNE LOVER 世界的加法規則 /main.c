#include<stdio.h>

void addition();

void print_binary(void *n){
    for(int i = 31; i >= 0; --i){
        printf("%d", (*(int *)n >> i) & 1);
        if (i && !(i % 8)) printf(" ");
    }
}

int main(){
    addition();
    return 0;
}

#include <math.h>

void intoArr(void *n, int arr[32]){
    for(int i = 31; i >= 0; --i){
        arr[i] = (*(int *)n >> i) & 1;
    }
}
void printArrSum(int arr_a[32], int arr_b[32], int arr_sum[32]) {
    int c = 0;
    for (int i = 0; i < 32; i++) {
        arr_sum[i] = arr_a[i] + arr_b[i] + c;
        c = 0;
        if (arr_sum[i] >= 2) {
            c = 1;
            arr_sum[i] -= 2;
        }
    }
    for (int i = 31; i >= 0; i--) {
        if (i % 8 == 7) printf(" ");
        printf("%d", arr_sum[i]);
    }
}

void printArrToBinary(int arr[32]) {
    unsigned int sum = 0;
    for (int i = 0, power = 0; i < 32; i++, power++) {
        if (arr[i] == 1) sum += pow(2, power);
        printf("%lf\n", pow(2, power));
    }
    printf("%d\n", sum);
}

void addition() {
    float a = 0, b = 0, sum = 0, tmp = 0;
    int arr_a[32] = {}, arr_b[32] = {}, arr_sum[32] = {};
    scanf("%f %f", &a, &b);
    intoArr(&a, arr_a);
    intoArr(&b, arr_b);
    sum = a + b;
    printf("   ");
    print_binary(&a);
    printf("\n");
    printf("+) ");
    print_binary(&b);
    printf("\n");
    printf("---------------------------------------\n");
    printf("  ");
    // 印出
    printArrSum(arr_a, arr_b, arr_sum);
    printf("\n");
    printf("%d + %d = ", (int)a, (int)b);
    printArrToBinary(arr_sum);
}

// 可以用 (float*)int* (int*)*float