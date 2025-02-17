#include <stdio.h>

int main() {

    char name[100];
    int id;
    int total_units_consumed;
    float fixed_charge = 100.0;
    float base_bill, surcharge = 0.0, total_bill;
    float rate_per_unit;

    // Input customer details
    printf("Enter Customer Name: ");
    scanf("%s",&name);
    printf("Enter Customer ID: ");
    scanf("%d", &id);
    printf("Enter Total Units Consumed: ");
    scanf("%d", &total_units_consumed);

    // Calculate rate per unit based on units consumed
    if (total_units_consumed <= 100) {
        rate_per_unit = 5.0;
    } else if (total_units_consumed <= 300) {
        rate_per_unit = 7.0;
    } else {
        rate_per_unit = 10.0;
    }

    // Calculate base bill
    base_bill = fixed_charge + (total_units_consumed * rate_per_unit);

    // Calculate surcharge if applicable
    if (base_bill > 1000) {
        surcharge = base_bill * 0.05; // 5% surcharge
    }

    // Calculate total bill
    total_bill = base_bill + surcharge;

    // Output results
    printf("\nCustomer Name: %s", name);
    printf("Customer ID: %d\n", id);
    printf("Units Consumed: %d\n", total_units_consumed);
    printf("Base Bill: ₹%.2f\n", base_bill);
    printf("Surcharge: ₹%.2f\n", surcharge);
    printf("Total Bill: ₹%.2f\n", total_bill);

    return 0;
}
