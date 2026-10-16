/*Task 09: Library Book Catalog
A library shelf holds 5 books. Read each title (with spaces) using the scanset scanf(" %[^\n]",
titles[i]) into char titles[5][50], and read its number of copies into an int. Then:
1. Print the catalog as a neat table.
2. Count the vowels in each title using nested loops.
3. Let the user enter a single letter, then show which titles start with that letter.
4. Print the title with the most copies.*/
#include <stdio.h>
#include <ctype.h>

int main() {
    char titles[5][50];
    int copies[5];
    int i, j, vowels;
    int maxCopies, bestBook = 0;
    char letter, ch;

    for(i = 0; i < 5; i++) {
        printf("Enter Book %d Title: ", i + 1);
        scanf(" %49[^\n]", titles[i]);

        printf("Enter Number of Copies: ");
        scanf("%d", &copies[i]);
    }

    printf("\nLibrary Book Catalog:\n");
    printf("%-5s %-30s %-10s\n",
           "No.", "Title", "Copies");

    for(i = 0; i < 5; i++) {
        printf("%-5d %-30s %-10d\n",
               i + 1, titles[i], copies[i]);
    }

    printf("\nVowel Count:\n");

    for(i = 0; i < 5; i++) {
        vowels = 0;

        for(j = 0; titles[i][j] != '\0'; j++) {
            ch = tolower(titles[i][j]);

            if(ch == 'a' || ch == 'e' ||
               ch == 'i' || ch == 'o' ||
               ch == 'u') {
                vowels++;
            }
        }

        printf("%s = %d vowels\n", titles[i], vowels);
    }

    printf("\nEnter Starting Letter: ");
    scanf(" %c", &letter);

    printf("Matching Books:\n");

    for(i = 0; i < 5; i++) {
        if(tolower(titles[i][0]) == tolower(letter)) {
            printf("%s\n", titles[i]);
        }
    }

    maxCopies = copies[0];

    for(i = 1; i < 5; i++) {
        if(copies[i] > maxCopies) {
            maxCopies = copies[i];
            bestBook = i;
        }
    }

    printf("\nBook with Most Copies:\n");
    printf("Title = %s\n", titles[bestBook]);
    printf("Copies = %d\n", maxCopies);

    return 0;
}

