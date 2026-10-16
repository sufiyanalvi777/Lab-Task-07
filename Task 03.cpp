/*Task 3: Weekly Temperature Report
A weather station records the temperature at 4 times of day (morning, noon, evening, night) for 7
days in temp[7][4]. Find the hottest and coldest readings with their day and time slot, and list
the days where the noon temperature was above the weekly noon average.*/
#include <stdio.h>

int main() {
    float temp[7][4];
    float hottest, coldest, noonSum = 0, noonAvg;
    int i, j;
    int hotDay = 0, hotTime = 0;
    int coldDay = 0, coldTime = 0;

    char times[4][10] = {
        "Morning", "Noon", "Evening", "Night"
    };

    for(i = 0; i < 7; i++) {
        printf("Enter 4 temperatures for Day %d:\n", i + 1);

        for(j = 0; j < 4; j++) {
            scanf("%f", &temp[i][j]);
        }
    }

    hottest = temp[0][0];
    coldest = temp[0][0];

    for(i = 0; i < 7; i++) {
        for(j = 0; j < 4; j++) {
            if(temp[i][j] > hottest) {
                hottest = temp[i][j];
                hotDay = i;
                hotTime = j;
            }

            if(temp[i][j] < coldest) {
                coldest = temp[i][j];
                coldDay = i;
                coldTime = j;
            }
        }

        noonSum += temp[i][1];
    }

    noonAvg = noonSum / 7;

    printf("\nHottest = %.2f, Day %d, %s\n",
           hottest, hotDay + 1, times[hotTime]);

    printf("Coldest = %.2f, Day %d, %s\n",
           coldest, coldDay + 1, times[coldTime]);

    printf("Weekly Noon Average = %.2f\n", noonAvg);

    printf("Days above Noon Average:\n");

    for(i = 0; i < 7; i++) {
        if(temp[i][1] > noonAvg) {
            printf("Day %d\n", i + 1);
        }
    }

    return 0;
}

