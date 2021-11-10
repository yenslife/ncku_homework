#include <stdio.h>

int main() {
    //費氏數列
    int w = 0;
    long int total = 0, beer_num = 0, i1 = 1;
    scanf("%d", &w);
    beer_num = w / 10;
    for (int i = 0; i <= beer_num; i++) {
        total = i1 + total;
        i1 = total - i1;
    }
    printf("%ld", total);
    return 0;
}
