#include <stdio.h>

int main() {
    int n;
    int cp1, cp2;
    float win = 0;
    float rate;
    scanf("%d", &n);
    float n1 = n;
    for (int check = 0; n > 0; n--, check = 0) {
        for (int i = 3; i > 0; i--) {
            scanf("%d %d", &cp1, &cp2);
            if (cp1 > cp2) {
                check++;
            } else if (cp1 < cp2) {
                check--;
            } else if (cp1 == cp2) {
                check += 0;
            }
        }
        if (check > 0) {
            win++;
            printf("Win\n");
        } else if (check < 0) {
            printf("Lose\n");
        } else if (check == 0) {
            printf("Tie\n");
        }
    }
    rate = (win / n1) * 100;
    printf("%.2f%%\n", rate);
    return 0;
}
