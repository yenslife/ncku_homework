#include <stdio.h>
#include <stdbool.h>

int main() {
    int n = 0, x = 0;
    char y = 0;
    const char plan_name[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
                                'R', 'S',
                                'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    bool check_plan_name[26] = {false};
    int box_name[26] = {0};

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        scanf(" %c", &y);
        for (int i = 0; i < 26; i++) {
            if (plan_name[i] == y) {
                check_plan_name[i] = true;
                box_name[i] = x;
                break;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        if (check_plan_name[i])
            printf("Plan %c is in box %d.\n", plan_name[i], box_name[i]);
        else
            printf("Not found plan %c.\n", plan_name[i]);
    }

    return 0;
}
