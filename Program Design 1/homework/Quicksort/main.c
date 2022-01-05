#include <stdio.h>

#define N 500
#define swap(x, y) {int tmp = x; x = y; y = tmp;}

void quicksort(int a[], int low, int high);

int partition(int a[], int low, int high);

int size;

int main(void) {
    int array[N];
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    quicksort(array, 0, size - 1);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}

void quicksort(int a[], int low, int high) {
    if (low >= high) return;
    int indexOfPivot = 0;      //partition會回傳一個index
    indexOfPivot = partition(a, low, high);
    for (int i = 0; i < low; i++) {
        printf("%d ", a[i]);
    }
    printf("[ ");
    for (int i = low; i < high + 1; i++) {
        if (i == indexOfPivot)
            printf("*");
        printf("%d ", a[i]);
    }
    printf("] ");
    for (int i = high + 1; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    quicksort(a, low, indexOfPivot - 1);
    quicksort(a, indexOfPivot + 1, high);
}

int partition(int a[500], int low, int high) {
    int pivot = a[high], indexOfSwapTarget = low - 1, indexOfCheckTarget = low, indexOfPivot = high;
    for (int i = low; i <= high; i++) {
        indexOfCheckTarget = i;
        if (a[indexOfCheckTarget] <= pivot && indexOfCheckTarget != high) {
            indexOfSwapTarget++;
            swap(a[indexOfCheckTarget], a[indexOfSwapTarget]);
        }
        if (indexOfCheckTarget == indexOfPivot && low + 1 == high) {
            if (a[low] > a[high]) {
                swap(a[low], a[high]);
                indexOfPivot = low;
                return indexOfPivot;
            } else {
                indexOfPivot = high;
                return indexOfPivot;
            }
        }
        if (indexOfCheckTarget == indexOfPivot) {
            indexOfSwapTarget++;
            swap(a[indexOfPivot], a[indexOfSwapTarget]);
            indexOfPivot = indexOfSwapTarget;
            return indexOfPivot;
        }

    }
}