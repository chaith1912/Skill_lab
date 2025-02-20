#include <stdio.h>

struct Employee_t {
    int id;
    char name[255];
    float salary;
    char department[50];
};
typedef struct Employee_t Employee; 

void readEmployee(Employee emp[], int n);
void displayEmployees(Employee emp[], int n);
Employee findHighestSalary(Employee emp[], int n);

int main() {
    int employeeCount;
    printf("Enter the number of employees: ");
    scanf("%d", &employeeCount);
    
    Employee employees[1000];
    readEmployee(employees, employeeCount);
    displayEmployees(employees, employeeCount);
    
    Employee highestSalariedEmployee = findHighestSalary(employees, employeeCount);
    printf("Employee with highest Salary: %s, %.2f (%s)\n",
           highestSalariedEmployee.name,
           highestSalariedEmployee.salary,
           highestSalariedEmployee.department);
    
    return 0;
}

void readEmployee(Employee emp[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details (ID, Name, Salary, Department): ");
        scanf("%d %s %f %s", &emp[i].id, emp[i].name, &emp[i].salary, emp[i].department);
    }
}

void displayEmployees(Employee emp[], int n) {
    printf("\nEmployee Details:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f, Department: %s\n",
               emp[i].id, emp[i].name, emp[i].salary, emp[i].department);
    }
}

Employee findHighestSalary(Employee emp[], int n) {
    Employee highest = emp[0];
    for (int i = 1; i < n; i++) {
        if (emp[i].salary > highest.salary) {
            highest = emp[i];
        }
    }
    return highest;
}
