#include <stdio.h>

int main() {
    int i,j, n;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    // Loop through each row
    for (i = 1; i <= n; i++) {
        // Loop to print the required number of '*' in each row
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        // Move to the next line after printing '*'.
        printf("\n");
    }

    return 0;
}