#include <stdio.h>
int *report_card (int *s) ;

int main () {
    int score[1001];
    int *show;
    int count = 0;

    do {
        scanf("%d", &score[count++]);
    } while (score[count - 1] != -1);

    show = report_card(score);

    count = 0;
    while (*(show + count) != -1) {
        printf("%d ", *(show + count));
        count++;
    }
}
int *report_card (int *s) {
    int maxNumber = 0, maxNumber2 = 0, begin = 0, end = 0, begin2 = 0, end2 = 0, i = 0;
    for (; *(s + i) != -1; i++) {
        if (*(s + i) >= 60) {
            if (maxNumber2 == 0) begin2 = i;
            maxNumber2 += *(s + i);
            end2 = i;
        } else if (*(s + i) < 60 && maxNumber2 != 0) {
            end2 = i;
            if ((end2 - begin2 > end - begin) || (end2 - begin2 == end - begin && maxNumber2 > maxNumber)) {
                end = end2;
                begin = begin2;
                maxNumber = maxNumber2;
            }
            maxNumber2 = 0;
        }
    }
    if (*(s + i - 1) >= 60) end2++;
    if ((end2 - begin2 > end - begin) || (end2 - begin2 == end - begin && maxNumber2 > maxNumber)) {
        end = end2;
        begin = begin2;
    }
    *(s + end) = -1;
    return (s + begin);
}