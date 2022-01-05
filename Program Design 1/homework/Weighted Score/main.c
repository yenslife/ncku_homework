#include <stdio.h>

struct weight {
    char chapter[10];
    int percent;
};

struct score {
    char chapter[10];
    int score;
};

struct report_card {
    char name[32];
    struct score record[10];
    int final;
    int max_score;
    int min_score;
};

void calculate (struct report_card[], struct weight[], int student_num, int chapter_num);

int main () {
    int student_num, chapter_num;
    struct weight chapter[10];
    struct report_card card[100];

    scanf("%d %d\n", &chapter_num, &student_num);
    for (int i = 0; i < chapter_num; ++i) {
        scanf("%d %s", &chapter[i].percent, chapter[i].chapter);
    }

    for (int i = 0; i < student_num; ++i) {
        scanf("%s", card[i].name);
        for (int j = 0; j < chapter_num; ++j) {
            scanf("%d %s", &card[i].record[j].score, card[i].record[j].chapter);
        }
    }

    calculate(card, chapter, student_num, chapter_num);

    for (int i = 0; i < student_num; ++i) {
        printf("%s %d %d %d\n", card[i].name, card[i].final, card[i].max_score, card[i].min_score);
    }
}
#include<string.h>
void calculate (struct report_card card[], struct weight chapter[], int student_num, int chapter_num) {
    // for final score
    for (int i = 0; i < student_num; i++) {
        card[i].final = 0;
        for (int j = 0; j < chapter_num; j++) {
            for (int k = 0; k < chapter_num; k++) {
                // 檢查有無match到name
                if (strcmp(card[i].record[j].chapter, chapter[k].chapter) == 0) {
                    card[i].final += (card[i].record[j].score * chapter[k].percent);
                }
            }
        }
        card[i].final /= 100;
    }
    // for max score and min
    int maxNum = 0, minNum = 101;
    for (int i = 0; i < student_num; i++) {
        for (int j = 0; j < chapter_num; j++) {
            if (card[i].record[j].score > maxNum) maxNum = card[i].record[j].score;
            if (card[i].record[j].score < minNum) minNum = card[i].record[j].score;
        }
        card[i].max_score = maxNum;
        card[i].min_score = minNum;
        maxNum = 0;
        minNum = 101;
    }
}
