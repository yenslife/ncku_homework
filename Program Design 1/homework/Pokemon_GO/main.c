#include <stdio.h>

int main() {
    int ball, cp, hp, speed, remain;
    scanf("%d %d %d %d", &ball, &cp, &hp, &speed);
    if (cp < 100) {
        remain = ball - 1;
        if (speed > 4) {
            printf("NO");
        } else {
            printf("YES \n%d", remain);
        }
    } else if (100 <= cp && cp <= 600) {
        if (hp > 100) {
            remain = ball - 8;
            if (remain > 0) {
                if (speed > 4) {
                    printf("NO");
                } else {
                    printf("YES \n%d", remain);
                }
            } else
                printf("NO");
        } else{
            remain = ball - 5;
        if (remain > 0) {
            printf("YES \n%d", remain);
        } else
            printf("NO");}
    } else if (cp > 600) {
        if (hp > 200) {
            remain = ball - 25;
            if (remain > 0) {
                if (speed > 4) {
                    printf("NO");
                } else {
                    printf("YES \n%d", remain);
                }
            } else {
                printf("NO");
            }
        } else {
            remain = ball - 15;
            if (remain > 0) {
                if (speed > 4) {
                    printf("NO");
                } else {
                    printf("YES \n%d", remain);
                }
            } else {
                printf("NO");
            }
        }

    }
    return 0;
}



