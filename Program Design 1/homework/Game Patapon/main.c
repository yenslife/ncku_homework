#include <stdio.h>
#include <string.h>
/*
PATA PATA PATA PON：可以前進一步。
PON PON PATA PON：可以原地攻擊怪物，扣除怪獸一滴血。
CHAKA CHAKA PATA PON：可以後退一步並防禦怪物攻擊。
*/
int distance = 0, blood = 0;

int main() {
    int commandTotal = 0, invalid = 0;
    char gogo[25] = "PATA PATA PATA PON";
    char attack[25] = "PON PON PATA PON";
    char back[25] = "CHAKA CHAKA PATA PON";
    scanf("%d %d", &distance, &blood);
    getchar();
    char command[25] = {};
    for (int i = 0;; i++) {
        scanf("%c", &command[i]);
        if (command[i] == ',' || command[i] == '.' || command[i] == '\n') {
            int r = (command[i] == '\n' ? 1:0);
            strcpy(command + i, "");
            //printf("cannabd:%s\n", command);
            if (strcmp(command, gogo) == 0) {
                distance--;
                commandTotal++;
            } else if (strcmp(command, attack) == 0) {
                if (distance <= 3) blood--;
                commandTotal++;
            } else if (strcmp(command, back) == 0) {
                distance++;
                commandTotal++;
            } else {
                invalid++;
            }
            if (distance == 0) {
                printf("NO %d\n", blood);
                break;
            }
            if (blood == 0) {
                printf("YES %d\n", commandTotal);
                break;
            }
            if ((commandTotal + invalid) % 10 == 0 && strcmp(command, back) != 0) {
                printf("NO %d\n", blood);
                break;
            }
            if (r){
                printf("NO %d\n", blood);
                break;
            }
            i = -1;
            strncpy(command, "", 25);
        }
    }
    return 0;
}