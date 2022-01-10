#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char s1[] = "";
    char s2[] = "a";
    // char *result = calloc(strlen(s1) + strlen(s2) + 1, sizeof(char));
    char* result = malloc(strlen(s1) + strlen(s2) + 1);
    // free(s1);
    free(result);
    result = NULL;
    // result = 0;
    if (result == NULL) {
        printf("Error: malloc failed in concat\n");
        exit(EXIT_FAILURE);
    }
    strcpy(result, s1);
    strcat(result, s2);
    // char *p = concat("abc", "def");
    printf("%s\n", result);
    printf("%d\n", *result);
}