#include<stdio.h>
#include<string.h>
int main()
{
    int id;
    char name[255];
    float salary;
    int attendance;

    printf("Enter id:");
    scanf("%d",&id);

    printf("Enter name:");
    scanf("%s",name);

    printf("Enter Salary:");
    scanf("%d",&salary);

    printf("Enter the numbers of days worked:");
    scanf("%d",&attendance);

    //process payroll
    float bonus = 0.0f;
    float gross_salary = 0.0f;
    char category[50] = "Good";

    //calculate bonus
    if(attendance > 25){
        bonus = (salary / 100.0f) * 5.0f;
    }   else if(attendance < 10){
            bonus = (-1.0f * ((salary / 100.0f) * 50.0f));
        }
    //final salary
    gross_salary = (salary + bonus);
    //categorize employee
    if(attendance > 25){
        strcpy(category,"Excellent");
    }else if(attendance < 15){
        strcpy(category,"NEED IMPROVEMENT");
    }
    
    // Display payroll details
    printf("PAYROLL DETAILS\n");
    printf("\tID:%d\n",id);
    printf("\tName:%s\n",name);
    printf("\tBasic Salary:%.2f\n",salary);
    if(bonus > 0){
        printf("\tBonus:%.2f\n",bonus);
    }
    printf("\t Final Salary:%.2f\n",gross_salary);
    printf("\t Employee Performance:%s\n",category);
    return 0;
}
