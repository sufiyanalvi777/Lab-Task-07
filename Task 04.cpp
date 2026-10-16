/*Task 4: Shop Sales Comparison
A shop sells 5 products across 3 branches. Read monthly sales into sales[3][5]. Print the total
sales per branch, total sales per product, the best-selling branch, and the product with the lowest
sales overall.

*/
#include <stdio.h>

int main() {
    int sales[3][5];
    int i, j, total;
    int highest = -1, lowest = -1;
    int bestBranch = 0, lowestProduct = 0;

    for(i = 0; i < 3; i++) {
        printf("Enter sales for Branch %d:\n", i + 1);

        for(j = 0; j < 5; j++) {
            scanf("%d", &sales[i][j]);
        }
    }

    for(i = 0; i < 3; i++) {
        total = 0;

        for(j = 0; j < 5; j++) {
            total += sales[i][j];
        }

        printf("Branch %d Total = %d\n", i + 1, total);

        if(total > highest) {
            highest = total;
            bestBranch = i + 1;
        }
    }

    for(j = 0; j < 5; j++) {
        total = 0;

        for(i = 0; i < 3; i++) {
            total += sales[i][j];
        }

        printf("Product %d Total = %d\n", j + 1, total);

        if(lowest == -1 || total < lowest) {
            lowest = total;
            lowestProduct = j + 1;
        }
    }

    printf("\nBest Selling Branch = %d\n", bestBranch);
    printf("Lowest Selling Product = %d\n", lowestProduct);

    return 0;
}

