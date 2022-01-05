#include <stdio.h>

#define SIZE 201

void modify_array(int *);

int main(void) {
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    modify_array(&arr[SIZE / 2]);
    for (int i = 1; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

void modify_array(int *arrP) {
    int newArr[SIZE] = {}, *arrStart = (arrP - SIZE / 2);
    if (*arrStart == 1) for (int i = 1; i < SIZE; i++) if (i % 2 == 1) *(arrStart + i) += 10;
    if (*arrStart == 2) for (int i = 1; i < SIZE; i++) if (i % 3 == 1) *(arrStart + i) *= 8;
    if (*arrStart == 2) for (int i = 1; i < SIZE; i++) if (i % 5 == 1) *(arrStart + i) -= 2;
}
