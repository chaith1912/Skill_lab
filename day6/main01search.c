#include<stdio.h>
int searchLinear(float * salaries, int size, float searchsalary);

int main(){
    float salaries[] = {20.0f, 10.0f, 15.0f, 12.0f,13.0f};
    int salariesCount = 5;
    float searchsalary = 20.0f;
    int index = searchLinear(salaries, salariesCount, searchsalary);
    printf("%.2f found at index %d\n",searchsalary,index);
    return 0;
}
int searchLinear(float * salaries, int size, float searchsalary){
    for(int i = 0; i < size; i++){
        if(salaries[i] == searchsalary){
            return i;
        }
    }
    return -1;
}