#include<stdio.h>

void displayAges(short int * ages,int size, int index){
    if(index == size){
    return;
    }
    printf("%d\n",ages[index]);

    displayAges(ages, size, index+1);
    
}

int main(){
    short int ages[]={45,42,14,20,70};
    displayAges(ages, 5, 0);
    return 0;
}