#include<stdio.h>
#include<stdlib.h>

struct snack
{
    int id;
    int price;
    int weight;
    double value;
};

int cmp(const void *a, const void *b);
void sort_snacks(struct snack snacks[], int n);

int main() {
    int n;
    struct snack snacks[100];
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        snacks[i].id = i+1;
        scanf("%d %d", &snacks[i].price, &snacks[i].weight);
    }
    sort_snacks(snacks, n);
    for(int i=0; i<n; i++) {
        printf("%d %.2f\n", snacks[i].id, snacks[i].value);
    }
    /*int test[5] = {5, 4, 6, 2, 7};
    qsort(test, 5, sizeof(int), cmp);
    for (int i = 0; i < 5; i++) printf("%d ", test[i]);
    return 0;*/
}
void sort_snacks(struct snack snacks[], int n) {
    double value[n];
    int id[n];
    for (int i = 0; i < n; i++) {
        snacks[i].value = (float)snacks[i].weight / (float )snacks[i].price;
        value[i] = snacks[i].value;
        id[i] = i + 1;
    }
    qsort(snacks, n, sizeof(struct snack), cmp);
}

int cmp(const void *a, const void *b) {
    struct snack *VA = (struct snack *)a;
    struct snack *VB = (struct snack *)b;
    if (VB->value - VA->value > 0) return 1;
    else if (VB->value - VA->value < 0) return -1;
    else if (VB->value - VA->value == 0) {
        if (VB->price - VA->price > 0) return -1;
        else if (VB->price - VA->price < 0) return 1;
        else if (VB->price - VA->price == 0) {
            if (VB->id - VA->id > 0) return -1;
            else if (VB->id - VA->id < 0) return 1;
            else return 0;
        }
    };

}