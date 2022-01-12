#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // strtok

int main() {
    char str[] = "Hello world, nice to meet you";
    const char* d = "  ,";
    char* p;
    printf("%d\n", strrchr(str, 'o') - str + 1);
    p = strtok(str, d);

    while (p != NULL) {
        printf("%s\n", p);
        p = strtok(NULL, d);
    }
    for (int i = 0; i < strlen(str); i++)
        printf("%c", str[i]);
        
    return 0;
}