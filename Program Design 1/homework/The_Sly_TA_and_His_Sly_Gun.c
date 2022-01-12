#include <stdio.h>
#include <string.h>

int n = 0;

union u {
    float f;
    unsigned char s[sizeof(float)];
};

union u foo;

int main() {
    /*float aaa = 1.0;
    unsigned char c[sizeof(float)];
    memcpy(c, &aaa, sizeof(aaa));*/
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int sum = 0;
        scanf("%f", &foo.f);
        for (int j = 0; j < 4; j++)
            sum += foo.s[j];
        if (sum % 2 == 0)
            printf("Front\n");
        else if (sum % 2 == 1)
            printf("Back\n");
    }
    return 0;
}