#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int group[100][3] = {};

int classifyTheGroup(int maxNumber, int quantityOfNumber[]); //分出小組的所有種類到 group[100][3]
int findTheLonelyNumber(int arr[], int quantityOfNumber[], int n);

//1 ≤ N ≤ 50，N = 3k + 1，k ∈ ℕ
//1 ≤ k ≤ 100

int main() {
    int n = 0, array[301] = {}, quantityOfNumber[1000] = {}, maxNumber = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    // 算數字的數量記到陣列 假設掃到數字是2 就在index 2 上加一
    for (int i = 0;; i++) {
        if (array[i] <= 0) break;
        quantityOfNumber[array[i]]++;
    }
    printf("%d", findTheLonelyNumber(array, quantityOfNumber, n));
    return 0;
}

int classifyTheGroup(int maxNumber, int quantityOfNumber[]) {
    int a = 0, b = 0, c = 0, groupNumber = 0;
    for (int i = 0; i <= maxNumber; i++) {
        if (quantityOfNumber[i] > 0) {
            a = i;
            for (int j = 0; j <= maxNumber; j++) {
                if ((quantityOfNumber[j] > 0 && j > i) ||
                    (quantityOfNumber[j] >= 2 && j >= i)) {
                    b = j;
                    for (int k = 0; k <= maxNumber; k++) {
                        if (k != i &&
                            k != j && quantityOfNumber[k] > 0) {
                            c = k;
                            if (a + b == c) {
                                group[groupNumber][0] = a;
                                group[groupNumber][1] = b;
                                group[groupNumber][2] = c;
                                groupNumber++;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
} // 這個好像用不到ㄌ

int findTheLonelyNumber(int arr[], int quantityOfNumber[], int n) {
    int tmp[1000] = {}, check = 0, lonelyIndex = 0, a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) tmp[i] = arr[i]; // 初始化暫存陣列
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i != j && i != k && j != k && tmp[i] + tmp[j] == tmp[k] && quantityOfNumber[tmp[i]] > 0 &&
                    quantityOfNumber[tmp[j]] > 0 && quantityOfNumber[tmp[k]] > 0 && tmp[i] != 0 && tmp[j] != 0 &&
                    tmp[k] != 0) {
                    printf("tmp[i] + tmp[j] == tmp[k]\n");
                    a = i;
                    b = j;
                    c = k;
                    printf("%d %d %d\n", tmp[a], tmp[b], tmp[c]);
                    quantityOfNumber[tmp[i]]--;
                    quantityOfNumber[tmp[j]]--;
                    quantityOfNumber[tmp[k]]--;
                    tmp[i] = 0;
                    tmp[j] = 0;
                    tmp[k] = 0;
                    for (int y = 0; y < 9; y++) {
                        printf("%d\n", quantityOfNumber[y]);
                    }
                    for (int i = 0; i < n; i++) printf("%d ", tmp[i]);
                    printf("\n");
                    for (int ii = 0; ii < n; ii++) {
                        if (tmp[ii] != 0) {
                            check++;
                            lonelyIndex = ii;
                        }
                    }
                    printf("check : %d\n", check);
                    if (check > 1) {
                        printf("check > 1 check : %d\n", check);
                        check = 0;
                        lonelyIndex = 0;
                        findTheLonelyNumber(tmp, quantityOfNumber, n);
                    }

                    if (check == 1) {
                        printf("check = %d return %d\n", check, tmp[lonelyIndex]);
                        return tmp[lonelyIndex];
                    }
                    if (check == 4) {
                        check = 0;
                        lonelyIndex = 0;
                        quantityOfNumber[tmp[a]]++;
                        quantityOfNumber[tmp[b]]++;
                        quantityOfNumber[tmp[c]]++;
                        tmp[a] = arr[a];
                        tmp[b] = arr[b];
                        tmp[c] = arr[c];
                        findTheLonelyNumber(tmp, quantityOfNumber, n);
                    }
                }
            }
        }
    }
}
