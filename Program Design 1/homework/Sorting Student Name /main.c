#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int N = 0;
    bool check[100] = {};
    char names[100][100], tmp[100][100], names2[100][100];   //可以用pointer寫嗎
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", names[i]);
    }
    //for (int i = 0; i < N; i++) printf("%s ", names[i]);
    // 'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122
    char maxName[100] = {'\0'}, *maxPointer;
    strcpy(tmp, names);
    int index = 0;
    //轉小寫
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (names[i][j] <= 'Z' && 'A' <= names[i][j]) tmp[i][j] = names[i][j] - 'A' + 'a';
            else tmp[i][j] = names[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (strcmp(tmp[j], maxName) >= 0 && check[j] != true) {
                strcpy(maxName, tmp[j]);
                maxPointer = tmp[j];
                index = j;
            }
        }
        for (int j = 0; j < 100; j++) if (maxPointer == tmp[j] && check != true) {
            check[j] = true;
            index = j;
        }
        strcpy(names2[i], names[index]);
        memset(maxName, 0, 100);
    }
    for (int i = N - 1; i >= 0; i--) printf("%s\n", names2[i]);
    return 0;
}
