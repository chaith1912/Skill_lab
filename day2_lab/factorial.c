#include <stdio.h>

long factorial(int n);

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        long fact = factorial(num);
        printf("Factorial of %d is %ld\n", num, fact);
    }

    return 0;
}

long factorial(int n) {
    if (n == 0) {
        return 1; // Base case: factorial of 0 is 1
    } else {
        return n * factorial(n - 1); // Recursive step
    }
}
