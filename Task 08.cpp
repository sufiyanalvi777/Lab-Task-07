/*Task 8: Warehouse Inventory
A warehouse has 3 buildings, 4 shelves per building, and 5 slots per shelf, stored in
stock[3][4][5]. Each element is the number of items in that slot. Print the total stock per
building, find the single fullest shelf and report its building and shelf number, and list every slot
with fewer than 5 items as “needs restock” along with its [building][shelf][slot] position.*/
#include <stdio.h>

int main() {
    int stock[3][4][5];
    int i, j, k, total, shelfTotal;
    int maxStock = -1;
    int bestBuilding = 0, bestShelf = 0;

    for(i = 0; i < 3; i++) {
        printf("\nBuilding %d\n", i + 1);

        for(j = 0; j < 4; j++) {
            printf("Enter 5 slots for Shelf %d:\n", j + 1);

            for(k = 0; k < 5; k++) {
                scanf("%d", &stock[i][j][k]);
            }
        }
    }

    for(i = 0; i < 3; i++) {
        total = 0;

        for(j = 0; j < 4; j++) {
            shelfTotal = 0;

            for(k = 0; k < 5; k++) {
                total += stock[i][j][k];
                shelfTotal += stock[i][j][k];
            }

            if(shelfTotal > maxStock) {
                maxStock = shelfTotal;
                bestBuilding = i + 1;
                bestShelf = j + 1;
            }
        }

        printf("Building %d Total Stock = %d\n", i + 1, total);
    }

    printf("\nFullest Shelf:\n");
    printf("Building = %d\n", bestBuilding);
    printf("Shelf = %d\n", bestShelf);
    printf("Total Items = %d\n", maxStock);

    printf("\nSlots Needing Restock:\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 4; j++) {
            for(k = 0; k < 5; k++) {
                if(stock[i][j][k] < 5) {
                    printf("[%d][%d][%d] Needs Restock\n",i + 1, j + 1, k + 1);
                }
            }
        }
    }

    return 0;
}

