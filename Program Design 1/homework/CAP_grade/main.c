#include <stdio.h>

//CAP grade
int main() {
    //會考成績換算輸出問題
    //運算的部分沒問題，用範例去試也都對，但結果是wrong answer
    //想確認我輸出的格式是否有誤，感謝大神！
    float EN, MA;
    int CH, SO, SC, score, point, A, B, C;
    A = 0;
    B = 0;
    C = 0;
    score = 0;
    point = 0;
    scanf("%d %f %f %d %d", &CH, &EN, &MA, &SO, &SC);
    //score
    if (41 <= CH && CH <= 48) {
        score += 6;
        A += 1;
    } else if (19 <= CH && CH <= 40) {
        score += 4;
        B += 1;
    } else if (0 <= CH && CH <= 18) {
        score += 2;
        C += 1;
    }
    if (90.24 <= EN && EN <= 100.00) {
        score += 6;
        A += 1;
    } else if (38.75 <= EN && EN <= 89.52) {
        score += 4;
        B += 1;
    } else if (0.00 <= EN && EN <= 38.70) {
        score += 2;
        C += 1;
    }
    if (81.73 <= MA && MA <= 100.00) {
        score += 6;
        A += 1;
    } else if (40.96 <= MA && MA <= 81.15) {
        score += 4;
        B += 1;
    } else if (0.00 <= MA && MA <= 40.19) {
        score += 2;
        C += 1;
    }
    if (56 <= SO && SO <= 63) {
        score += 6;
        A += 1;
    } else if (23 <= SO && SO <= 55) {
        score += 4;
        B += 1;
    } else if (0 <= SO && SO <= 22) {
        score += 2;
        C += 1;
    }
    if (46 <= SC && SC <= 54) {
        score += 6;
        A += 1;
    } else if (20 <= SC && SC <= 45) {
        score += 4;
        B += 1;
    } else if (0 <= SC && SC <= 19) {
        score += 2;
        C += 1;
    }
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
    // CH point

    if (45 <= CH && CH <= 48) {
        point += 7;
    } else if (43 <= CH && CH <= 44) {
        point += 6;
    } else if (41 <= CH && CH <= 42) {
        point += 5;
    } else if (36 <= CH && CH <= 40) {
        point += 4;
    } else if (31 <= CH && CH <= 35) {
        point += 3;
    } else if (19 <= CH && CH <= 30) {
        point += 2;
    } else if (0 <= CH && CH <= 18) {
        point += 1;
    }
    // EN point
    if (98.05 <= EN && EN <= 100.00) {
        point += 7;
    } else if (95.15 <= EN && EN <= 97.14) {
        point += 6;
    } else if (90.24 <= EN && EN <= 94.29) {
        point += 5;
    } else if (81.58 <= EN && EN <= 89.52) {
        point += 4;
    } else if (69.83 <= EN && EN <= 81.53) {
        point += 3;
    } else if (38.75 <= EN && EN <= 69.78) {
        point += 2;
    } else if (0 <= EN && EN <= 38.70) {
        point += 1;
    }
    // MA point
    if (94.23 <= MA && MA <= 100.00) {
        point += 7;
    } else if (90.19 <= MA && MA <= 93.46) {
        point += 6;
    } else if (81.73 <= MA && MA <= 90.00) {
        point += 5;
    } else if (72.12 <= MA && MA <= 81.15) {
        point += 4;
    } else if (63.08 <= MA && MA <= 71.92) {
        point += 3;
    } else if (40.96 <= MA && MA <= 62.31) {
        point += 2;
    } else if (0.00 <= MA && MA <= 40.19) {
        point += 1;
    }
    // SO point
    if (61 <= SO && SO <= 63) {
        point += 7;
    } else if (59 <= SO && SO <= 60) {
        point += 6;
    } else if (56 <= SO && SO <= 58) {
        point += 5;
    } else if (48 <= SO && SO <= 55) {
        point += 4;
    } else if (39 <= SO && SO <= 47) {
        point += 3;
    } else if (23 <= SO && SO <= 38) {
        point += 2;
    } else if (0 <= SO && SO <= 22) {
        point += 1;
    }
    // SC point
    if (52 <= SC && SC <= 54) {
        point += 7;
    } else if (50 <= SC && SC <= 51) {
        point += 6;
    } else if (46 <= SC && SC <= 49) {
        point += 5;
    } else if (38 <= SC && SC <= 45) {
        point += 4;
    } else if (31 <= SC && SC <= 37) {
        point += 3;
    } else if (20 <= SC && SC <= 30) {
        point += 2;
    } else if (0 <= SC && SC <= 19) {
        point += 1;
    }
    printf("%d/%d(", score, point);
    if (A != 0) {
        printf("%dA", A);
    }
    if (B != 0) {
        printf("%dB", B);
    }
    if (C != 0) {
        printf("%dC", C);
    }
    printf(")");
    return 0;
}
