#include <stdio.h>
#include <string.h>
#define MAX_LEN_P 100000
#define MAX_LEN_S 100

void strins(char *P, char *s, char *t);

int main() {
    char P[MAX_LEN_P + 1], s[MAX_LEN_S + 2], t[MAX_LEN_S + 2];
    size_t P_len = 0;
    for (char buf[MAX_LEN_P + 1] = ""; strcmp(buf, "---\n"); fgets(buf, MAX_LEN_P + 1, stdin)) {
        size_t len = strlen(buf);
        if (len + P_len > MAX_LEN_P) {
            fprintf(stderr, "The length of the paragraph exceeds %d\n", MAX_LEN_P);
            return 1;
        }
        strncat(P, buf, len + 1);
        P_len += len;
    }
    fgets(s, MAX_LEN_S + 2, stdin);
    s[strlen(s) - 1] = '\0';  // remove newline
    fgets(t, MAX_LEN_S + 2, stdin);
    t[strlen(t) - 1] = '\0';  // remove newline
    strins(P, s, t);
    printf("%s", P);
    return 0;
}
// P 是原本那坨, s 是目標字串, t是要加的字串
// 應該會用到strncpy
void strins(char *P, char *s, char *t) {
    int len = strlen(P), targetLength = strlen(s);
    char tmp[MAX_LEN_P] = "";
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < targetLength; j++) {
            tmp[j] = P[i + j];
        }
        if (strcmp(s, tmp) == 0) {
            i = i + targetLength;
            len += strlen(t);
            char copy[MAX_LEN_P] = "";
            strcpy(copy, P + i);
            //strncpy(P + i + targetLength, "", len - targetLength - i);
            *(P + i + targetLength) = '\0';
            strcpy(P + i, t);
            strcat(P + i, copy);
        }
    }
}