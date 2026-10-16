/*TASK 1: CINEMA SEAT BOOKING
A cinema hall has 5 rows and 8 seats per row. Seats are stored in seats[5][8] (0 = empty, 1 =
booked). Read the booking status of every seat, then print the seating map using . for empty and
X for booked. Also report how many seats are free in each row and in total.*/
#include <stdio.h>

int main() {
    int seats[5][8];
    int i, j, freeSeats, totalFree = 0;

    for(i = 0; i < 5; i++) {
        printf("Enter seats for Row %d (0 or 1):\n", i + 1);
        for(j = 0; j < 8; j++) {
            scanf("%d", &seats[i][j]);
        }
    }

    printf("\nCinema Seating Map:\n");

    for(i = 0; i < 5; i++) {
        freeSeats = 0;

        printf("Row %d: ", i + 1);

        for(j = 0; j < 8; j++) {
            if(seats[i][j] == 0) {
                printf(". ");
                freeSeats++;
            } else {
                printf("X ");
            }
        }

        printf(" Free Seats = %d\n", freeSeats);
        totalFree += freeSeats;
    }

    printf("\nTotal Free Seats = %d\n", totalFree);

    return 0;
}

