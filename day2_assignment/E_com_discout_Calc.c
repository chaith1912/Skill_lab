#include <stdio.h>

// Function to calculate the final payable amount after discount
float calculateFinalAmount(float billAmount) {
    if (billAmount > 1000) {
        return billAmount * 0.8; // 20% discount
    } else if (billAmount >= 500) {
        return billAmount * 0.9; // 10% discount
    } else
        return billAmount; // No discount
    }


int main() {
    float billAmount;
    printf("Enter total bill amount: Rs.");
    scanf("%f", &billAmount);

    float finalAmount = calculateFinalAmount(billAmount);
    printf("Final Payable Amount: Rs.%.2f\n", finalAmount);

    return 0;
}