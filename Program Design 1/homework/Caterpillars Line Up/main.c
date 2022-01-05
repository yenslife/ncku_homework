#include<stdio.h>
#include<stdbool.h>

void lineup_again(char line[]);
void swap(char *a, char *b);
void reverse_caterpillar(char *l, char *r);

int main() {
    char line[1000000];
    scanf("%s", line);
    lineup_again(line);
    printf("%s", line);
}
#include <string.h>
void swap(char *a, char *b) {
    char tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse_caterpillar(char *l, char *r) {
    int len = l - r + 1;
    for (int i = 0; i < len / 2; i++) {
        //printf("%c %c\n", *(l - i), *(r + i));
        swap(l - i, r + i);
        if (i == len / 2) break;
    }
}

void lineup_again(char line[]) {
    int a = -1, z = -1;
    //printf("strlen = %d\n", strlen(line));
    for (int i = 0; i < strlen(line) + 1; i++) {
        if (line[i] == 'Z') {
            z = i;
        } else if (line[i] == 'A') {
            a = i;
        }
        if (z != -1 && a > z && a != -1) {
            reverse_caterpillar(line + a, line + z);
            a = -1;
            z = -1;
        } else if (z != -1 && a != -1 && a < z) {
            a = -1;
            z = -1;
        }
    }
    //reverse_caterpillar(line,line + strlen(line) - 1);
}