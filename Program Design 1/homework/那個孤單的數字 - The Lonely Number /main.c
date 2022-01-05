#include <stdio.h>
#include <stdlib.h>

int n = 0;

int findTheLonelyNumber(int arr[], int quantityOfNumber[]);

int cmp(const void *a, const void *b)  //這個比較穩 可以在c文件裡找到
{
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

//1 ≤ N ≤ 50，N = 3k + 1，k ∈ ℕ
//1 ≤ k ≤ 100

int main() {
    int array[301] = {}, quantityOfNumber[1000] = {}, maxNumber = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    // 算數字的數量記到陣列 假設掃到數字是2 就在index 2 上加一
    for (int i = 0;; i++) {
        if (array[i] <= 0) break;
        quantityOfNumber[array[i]]++;
    }
    // qsort(array, n, sizeof(int), cmp);
    printf("%d", findTheLonelyNumber(array, quantityOfNumber));
    return 0;
}

int findTheLonelyNumber(int arr[], int quantityOfNumber[]) {
    int tmp[1000] = {}, a = 0, b = 0, c = 0;
    int check = 0, lonelyNumber = 0;
    //for (int i = 0; i < n; i++) tmp[i] = arr[i];
    for (int i = 0; i < 500; i++) {
        if (quantityOfNumber[i]) {
            check += quantityOfNumber[i];
            lonelyNumber = i;
        }
    }
    if (check == 1) {
        return lonelyNumber;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && quantityOfNumber[arr[i]] &&
                quantityOfNumber[arr[j]] && quantityOfNumber[arr[i] + arr[j]] && (
                        arr[i] == arr[j] ? (quantityOfNumber[arr[i]] > 1 ? 1 : 0) : 1)) {
                quantityOfNumber[arr[i]]--;
                quantityOfNumber[arr[j]]--;
                quantityOfNumber[arr[i] + arr[j]]--;
                int r = findTheLonelyNumber(arr, quantityOfNumber);
                if (r) return r;
                quantityOfNumber[arr[i]]++;
                quantityOfNumber[arr[j]]++;
                quantityOfNumber[arr[i] + arr[j]]++;
            }
        }
    }
    return 0;
}
