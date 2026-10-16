/*Task 2: Student Marks Sheet
A teacher has 6 students and 4 subjects. Read the marks into marks[6][4]. Print each student’s
total and average, each subject’s class average, and the name of the subject (by number) where
the class performed best.*/
#include <stdio.h>

int main() {
    int marks[6][4];
    int i, j, total;
    float avg, subjectAvg[4];
    float highest = -1;
    int bestSubject = 0;

    for(i = 0; i < 6; i++) {
        printf("Enter marks for Student %d:\n", i + 1);

        for(j = 0; j < 4; j++) {
            scanf("%d", &marks[i][j]);
        }
    }

    for(i = 0; i < 6; i++) {
        total = 0;

        for(j = 0; j < 4; j++) {
            total += marks[i][j];
        }

        avg = total / 4.0;

        printf("Student %d: Total = %d, Average = %.2f\n", i + 1, total, avg);
    }

    for(j = 0; j < 4; j++) {
        total = 0;

        for(i = 0; i < 6; i++) {
            total += marks[i][j];
        }

        subjectAvg[j] = total / 6.0;

        printf("Subject %d Average = %.2f\n",j + 1, subjectAvg[j]);

        if(subjectAvg[j] > highest) {
            highest = subjectAvg[j];
            bestSubject = j + 1;
        }
    }

    printf("\nBest Performing Subject = %d\n", bestSubject);

    return 0;
}

