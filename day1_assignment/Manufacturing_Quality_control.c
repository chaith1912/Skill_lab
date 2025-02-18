#include<stdio.h>

int main(){
    int count;
    int weight;

    printf("Enter number of products:");
    scanf("%d",&count);

    int acceptedCount = 0;
    int rejectedCount = 0;
    for(int i=1; i<= count; i++){
        printf("Enter the weight(in grams):");
        scanf("%d",&weight);
        if(weight >= 950 && weight <= 1050){
            acceptedCount++;
        } else {
            rejectedCount++;
        }
    }
    printf("Accepted Product:%d\n",acceptedCount);
    printf("Rejected Product:%d\n",rejectedCount);

    return 0;
}