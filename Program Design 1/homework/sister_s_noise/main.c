#include <stdio.h>

int main() {
    //Noise(A, B) = (M + N) x |A - B|
    int s[10] = {0};
    int m = 0, n = 0, a = 0, b = 0;
    int max_noice = 0;
    int final_noice = 0;
    for (int i = 0; i < 10 ; i ++){
        scanf("%d", &s[i]);
    }
    for (int i = 0; i < 10; i++,a++){
        m = s[i];
        for (b = i + 1, a = i;b < 10; b++){
            n = s[b];
            max_noice = (m + n) * (b - a);
            if (max_noice > final_noice){
                final_noice = max_noice;
            }
        }
    }
    printf("%d", final_noice);
    return 0;
}
