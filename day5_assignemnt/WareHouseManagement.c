#include <stdio.h>
#include <string.h>

#define MAX 100

char stock[MAX][100];  
int top = -1;

void addStock() {
    if (top == MAX - 1) {
        printf("Warehouse is full!\n");
        return;
    }
    printf("Enter item name: ");
    scanf("%s", stock[++top]);
    printf("Stock Added: %s\n", stock[top]);
}

void dispatchStock() {
    if (top == -1) {
        printf("No stock available for dispatch.\n");
        return;
    }
    printf("Dispatching Item: %s\n", stock[top--]);
}

void showStock() {
    if (top == -1) {
        printf("No stock available.\n");
        return;
    }
    printf("Remaining Stock: ");
    for (int i = 0; i <= top; i++) {
        printf("%s", stock[i]);
        if (i < top) printf(", ");
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Stock\n2. Dispatch Stock\n3. Show Stock\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStock(); break;
            case 2: dispatchStock(); break;
            case 3: showStock(); break;
            case 4: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}