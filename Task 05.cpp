/*Task 5: Hotel Room Occupancy Grid
A hotel has 4 floors with 6 rooms each, stored in rooms[4][6]. Read 1 for occupied and 0 for
vacant. Find the floor with the most vacancies. Then check whether any floor has 3 or more
consecutive vacant rooms, and print the floor and the starting room number.*/
#include <stdio.h>

int main() {
    int rooms[4][6];
    int i, j, vacant, maxVacant = -1;
    int bestFloor = 0, count, found = 0;

    for(i = 0; i < 4; i++) {
        printf("Enter rooms for Floor %d (0 or 1):\n", i + 1);

        for(j = 0; j < 6; j++) {
            scanf("%d", &rooms[i][j]);
        }
    }

    for(i = 0; i < 4; i++) {
        vacant = 0;

        for(j = 0; j < 6; j++) {
            if(rooms[i][j] == 0) {
                vacant++;
            }
        }

        printf("Floor %d Vacant Rooms = %d\n", i + 1, vacant);

        if(vacant > maxVacant) {
            maxVacant = vacant;
            bestFloor = i + 1;
        }
    }

    printf("\nFloor with Most Vacancies = %d\n", bestFloor);

    for(i = 0; i < 4; i++) {
        count = 0;

        for(j = 0; j < 6; j++) {
            if(rooms[i][j] == 0) {
                count++;
            } else {
                count = 0;
            }

            if(count == 3) {
                printf("Floor %d: 3 consecutive vacant rooms starting at Room %d\n",i + 1, j - 1);
                found = 1;
            }
        }
    }

    if(found == 0) {
        printf("No floor has 3 consecutive vacant rooms.\n");
    }

    return 0;
}

