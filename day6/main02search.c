#include <stdio.h>

int searchlinear(float *salaries, int size, float searchsalary);

int main() {
    
    float salaries[] = {20.0f, 10.0f, 15.0f, 12.0f, 13.0f}; 
    int salariesCount = 5;
    float searchsalary = 20.0f;

    
    int index = searchlinear(salaries, salariesCount, searchsalary);

    
    printf("%.2f found at index %d\n", searchsalary, index); 
    return 0; //
}


int searchlinear(float *salaries, int size, float searchsalary) {
    for (int i = 0; i < size; i++) { 
        if (salaries[i] == searchsalary) { 
            return i;    
        }
    }
    return -1; 
}
int searchBinary(float*salaries,int size,float searchsalary){
    int left=0,right=size-1;

    while(left<=right){
        int mid=(left+right)/2;
        if(salaries[mid]==searchsalary){
            return mid;

    }else if(searchsalary<salaries[mid]){
        right=mid-1;
    }else{
        left=mid+1;
    }
    }
}