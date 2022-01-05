#include <stdio.h>

// black tea (L)/ White gourd (L)/Tieguanyin tea (L)/green tea (L)/milk (L)/sugar (kg)/ice (kg).

int main() {
    // ingredient
    int blackTea = 0, whiteGourd = 0, tieguanyinTea = 0, greenTea = 0, milk = 0, sugar = 0, ice = 0, n = 0, sum = 0;
    char kind = 0;
    int sugarLevel = 0, iceLevel = 0;
    scanf("%d %d %d %d %d %d %d", &blackTea, &whiteGourd, &tieguanyinTea, &greenTea, &milk, &sugar, &ice);
    blackTea *= 1000;
    whiteGourd *= 1000;
    tieguanyinTea *= 1000;
    greenTea *= 1000;
    milk *= 1000;
    sugar *= 1000;
    ice *= 1000;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%c", &kind);
        scanf("%c", &kind);
        if (kind == 'G') {
            scanf("%c", &kind);
            if (kind == 'T') {          // GT
                tieguanyinTea -= 250;
                greenTea -= 250;
                sum += 45;
                scanf("%c", &kind);
            } else if (kind == ' ') {   // G
                greenTea -= 500;
                sum += 20;
                kind = '0';
            }
        } else if (kind == 'B') {
            scanf("%c", &kind);
            if (kind == 'M') {          // BM
                blackTea -= 200;
                milk -= 300;
                sum += 35;
                scanf("%c", &kind);
            } else if (kind == ' ') {   // B
                blackTea -= 500;
                sum += 20;
                kind = '0';
            }
        } else if (kind == 'T') {
            scanf("%c", &kind);
            if (kind == 'M') {          // TM
                tieguanyinTea -= 200;
                milk -= 300;
                sum += 45;
                scanf("%c", &kind);
            } else if (kind == ' ') {   // T
                tieguanyinTea -= 500;
                sum += 30;
                kind = '0';
            }
        } else if (kind == 'W') {
            scanf("%c", &kind);
            if (kind == 'T') {          // WT
                tieguanyinTea -= 350;
                whiteGourd -= 150;
                sum += 40;
                scanf("%c", &kind);
            } else if (kind == 'M') {   // WM
                whiteGourd -= 200;
                milk -= 300;
                sum += 30;
                scanf("%c", &kind);
            } else if (kind == ' ') {   // W
                whiteGourd -= 500;
                sum += 15;
                kind = '0';
            }
        }
        scanf("%d/%d", &sugarLevel, &iceLevel);
        switch (sugarLevel) {
            case 1:
                sugar -= 0;
                break;
            case 2:
                sugar -= 3;
                break;
            case 3:
                sugar -= 5;
                break;
            case 4:
                sugar -= 7;
                break;
            case 5:
                sugar -= 10;
                break;
        }
        switch (iceLevel) {
            case 1:
                ice -= 0;
                break;
            case 2:
                ice -= 30;
                break;
            case 3:
                ice -= 50;
                break;
            case 4:
                ice -= 70;
                break;
            case 5:
                ice -= 100;
                break;
        }
    }
    printf("%d %d %d %d %d %d %d\n%d", blackTea, whiteGourd, tieguanyinTea, greenTea, milk, sugar, ice, sum);
    return 0;
}
// black tea (L)/ White gourd (L)/Tieguanyin tea (L)/green tea (L)/milk (L)/sugar (kg)/ice (kg).
