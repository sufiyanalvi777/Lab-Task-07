/*Task 7: University Result System
A university has 3 departments, 4 students per department, and 5 subjects each, stored in
marks[3][4][5]. Print every student’s average, the topper of each department, and the
department with the highest overall average. Mark any student with a subject below 40 as
“FAIL”.*/
#include <stdio.h>

int main() {
    int marks[3][4][5];
    int i, j, k, total, fail;
    int topper;
    int bestDept = 0;
    float avg, highest, deptTotal;
    float bestAvg = -1;

    for(i = 0; i < 3; i++) {
        printf("\nDepartment %d\n", i + 1);

        for(j = 0; j < 4; j++) {
            printf("Enter 5 marks for Student %d:\n", j + 1);

            for(k = 0; k < 5; k++) {
                scanf("%d", &marks[i][j][k]);
            }
        }
    }

    for(i = 0; i < 3; i++) {
        highest = -1;
        topper = 0;
        deptTotal = 0;

        printf("\nDepartment %d Results:\n", i + 1);

        for(j = 0; j < 4; j++) {
            total = 0;
            fail = 0;

            for(k = 0; k < 5; k++) {
                total += marks[i][j][k];

                if(marks[i][j][k] < 40) {
                    fail = 1;
                }
            }

            avg = total / 5.0;
            deptTotal += total;

            printf("Student %d Average = %.2f", j + 1, avg);

            if(fail == 1) {
                printf(" FAIL");
            }

            printf("\n");

            if(avg > highest) {
                highest = avg;
                topper = j + 1;
            }
        }

        printf("Department Topper = Student %d\n", topper);

        avg = deptTotal / 20.0;

        printf("Department Average = %.2f\n", avg);

        if(avg > bestAvg) {
            bestAvg = avg;
            bestDept = i + 1;
        }
    }

    printf("\nBest Department = %d\n", bestDept);
    printf("Highest Department Average = %.2f\n", bestAvg);

    return 0;
}

