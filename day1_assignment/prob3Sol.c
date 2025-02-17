#include <stdio.h>
#include <string.h>

int main() {
    int paymentMethod;
    char cardNumber[17];
    char upiID[50];
    int bankOption;

    // select a payment method
    printf("Select Payment Method (1-3):\n");
    printf("1. Credit/Debit Card\n");
    printf("2. UPI\n");
    printf("3. Net Banking\n");
    scanf("%d", &paymentMethod);

    // Process the selected payment method
    switch (paymentMethod) {

        case 1:
            // Credit/Debit Card
            printf("Enter your 16-digit card number: ");
            scanf("%s", cardNumber);
            if (strlen(cardNumber) == 16) {
                printf("Payment Successful!\n");
            } else {
                printf("Transaction Failed. Please try again.\n");
            }
            break;

        case 2:
            // UPI
            printf("Enter your UPI ID: ");
            scanf("%s", upiID);
            if (strchr(upiID, '@') != NULL) { //checks whether '@' is present or not.
                printf("Payment Successful!\n");
            } else {
                printf("Transaction Failed. Please try again.\n");
            }
            break;

        case 3:
            // Net Banking
            printf("Select your bank (1 for SBI, 2 for HDFC): ");
            scanf("%d", &bankOption);
            if (bankOption == 1 || bankOption == 2) {
                printf("Payment Successful!\n");
            } else {
                printf("Transaction Failed. Please try again.\n");
            }
            break;
            
        default:
            // Invalid payment method
            printf("Invalid payment method. Please try again.\n");
            break;
    }

    return 0;
}