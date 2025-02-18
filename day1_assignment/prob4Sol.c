#include<stdio.h>
void readDetails(float * p_salary,int * p_score,int * p_experience){
    printf("Enter salary:");
    scanf("%f",p_salary);

    printf("Enter Credit Score:");
    scanf("%f",p_score);

    printf("Enter Experience:");
    scanf("%f",p_experience);
}
int isEligible(float salary, int score, int experience){
    return((salary >= 30000)&&(score >= 750)&&(experience >= 2));
}

int main()
{
    float salary;
    int score;
    int experience;
    readDetails(&salary,&score,&experience);
    if(isEligible(salary,score,experience)){
        printf("LOAN APPROVED");
    }
    else{
        printf("LOAN REJECTED");
    }

    return 0;
}