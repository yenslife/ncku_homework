#include <stdio.h>
#include <string.h>
#include<assert.h>


void REVERSE();

void TO_UPPER();

void TO_LOWER();

void REMOVE();

void COMPRESS();

int length = 0;
char str[8000] = {};
int main() {
    char mode[10] = {};
    int N = 0;
    for (int i = 0;; i++) {
        char tmp = getchar();
        if (tmp == '\n') break;
        else str[i] = tmp;
        length++;
    }
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", &mode);
        if (!strcmp(mode, "PRINT")) printf("%s\n", str);
        if (!strcmp(mode, "REVERSE")) REVERSE(str);
        if (!strcmp(mode, "TO_UPPER")) TO_UPPER(str);
        if (!strcmp(mode, "TO_LOWER")) TO_LOWER(str);
        if (!strcmp(mode, "REMOVE")) REMOVE(str);
        if (!strcmp(mode, "COMPRESS")) COMPRESS(str);
    }
    return 0;
}

void REVERSE() {
    char tmp[8000] = {};
    for (int i = 0, j = length - 1; i < length; i++, j--) tmp[j] = str[i];
    for (int i = 0; i < length; i++) str[i] = tmp[i];
    printf("%s\n", str);
}

void TO_UPPER() {
    char tmp[8000] = {};
    for (int i = 0; i < length; i++) {
        if ('a' <= str[i] && str[i] <= 'z') tmp[i] = str[i] + 'A' - 'a';
        else tmp[i] = str[i];
        str[i] = tmp[i];
    }
    printf("%s\n", str);
}

void TO_LOWER() {
    char tmp[8000] = {};
    for (int i = 0; i < length; i++) {
        if ('A' <= str[i] && str[i] <= 'Z') tmp[i] = str[i] - 'A' + 'a';
        else tmp[i] = str[i];
        str[i] = tmp[i];
    }
    printf("%s\n", str);
}

void REMOVE() {
    char target = '0', tmp[8000] = {};
    int tmpLength = length;
    target = getchar();
    target = getchar();
    for (int i = 0, k = 0; i < tmpLength; i++) {
        if (str[i] != target) {
            tmp[k++] = str[i];
        } else if (str[i] == target) length--;
    }
    for (int i = 0; i < 8000; i++) str[i] = tmp[i];
    printf("%s\n", str);
}

void COMPRESS() {
    char target = '0', tmp[8000] = {};
    int number = 0, times = 0, tmpLength = length;
    for (int i = 0; i < tmpLength; i++) {
        if (str[i] != target || i == 0) {
            target = str[i];
            number = 0;
        }
        number++;
        if (str[i] != str[i + 1]) {
            tmp[times] = '-';
            tmp[times + 1] = target;
            if (1 <= number && number <= 9) {
                tmp[times + 2] = number + '0';
                times+=3;
            } else if (10 <= number && number <= 99) {
                tmp[times + 2] = number / 10 + '0';
                tmp[times + 3] = number % 10 + '0';
                times+=4;
            } else if (100 <= number && number <= 999) {
                tmp[times + 2] = number / 100 + '0';
                tmp[times + 3] = number / 10 % 10 + '0';
                tmp[times + 4] = number  % 10 + '0';
                times+=5;
            } else if (1000 <= number && number <= 9999) {
                tmp[times + 2] = number / 1000 + '0';
                tmp[times + 3] = number / 100 % 10 + '0';
                tmp[times + 4] = number / 10 % 10 + '0';
                tmp[times + 5] = number % 10 + '0';
                times+=6;
            }
        }
    }
    length = times;
    for (int i = 0; i < 8000; i++) str[i] = tmp[i];
    printf("%s\n", str);
}