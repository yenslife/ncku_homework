#include <stdio.h>

int main() {
    //4 710367 66327
    int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, sum1, sum2, check;
    scanf("%1d %1d%1d%1d%1d%1d%1d %1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11, &i12);
    sum1 = (i1 + i3 + i5 + i7 + i9 + i11) + (i2 + i4 + i6 + i8 + i10 + i12)*3 - 1;
    sum2 = sum1 % 10;
    check = 9 - sum2;
    printf("%d", check);
    return 0;
}
