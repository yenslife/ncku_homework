#include <stdio.h>

int main() {
    int n = 0, min = 0, hour = 0, train = 0, minT = 0, hourT = 0, time = 0, smallestMin = 999, smallestHour = 999, smallestTrain = 0, minSum = 0, hourSum = 0;
    scanf("%d:%d", &hour, &min);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d:%d %d", &train, &hourT, &minT, &time);
        if (hour > hourT || (hour >= hourT && min > minT));
        else {
            if (time / 60 != 0) {
                hourSum = time / 60;
                minSum = time - (time / 60) * 60;
            } else {
                hourSum = 0;
                minSum = time;
            }
            if (minT + minSum >= 60) {
                hourSum++;
                minSum = minT + minSum - 60;
                hourSum += hourT;
            } else if (minT + minSum < 60) {
                hourSum += hourT;
                minSum = minT + minSum;
            }

            if ((hourSum <= smallestHour && minSum < smallestMin) || (hourSum < smallestHour)) {
                smallestHour = hourSum;
                smallestMin = minSum;
                smallestTrain = train;
            }
        }
    }
    printf("%d", smallestTrain);
    return 0;
}
