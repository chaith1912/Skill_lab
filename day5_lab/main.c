
#include <stdio.h>
#include "Student.h"
#include "queue.c"

void readStudentDetails(int n, Student students[]);
void calculateTotalAndAverage(int n, Student students[]);
void displayStudentDetails(int n, Student students[]);
void displayStudentDetailsUsingQueue(int n, Student students[]);
void createfile(int n, Student students[]);
void manageStudents();

int main(){
    manageStudents();
    return 0;
}

void manageStudents(){
    int n;
    Student students[100];
    int choice;
    do{
        printf("Choices:\n");
        printf("1-Read Students\n");
        printf("2-Display Students\n");
        printf("3-Display Students using Queue\n");
        printf("91-Exit\n");
        printf("Your Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                printf("Enter number of students: ");
                scanf("%d", &n);
                readStudentDetails(n, students);
                calculateTotalAndAverage(n, students);
                createfile(n, students);
            } break;
            case 2: {
                displayStudentDetails(n, students);
            } break;
            case 3: {
                displayStudentDetailsUsingQueue(n, students);
            } break;
            case 4:{
                printf("Thank you for using the App :)...\n");
            } break;
        }
    }while(choice != 91);
}


void readStudentDetails(int n, Student students[]){
    for(int i = 0 ; i < n ; i++){
        printf("Student %d details",i+1);
        printf("Roll No: ");
        scanf("%d",students[i].rollNo);
        printf("Name: ");
        scanf("%d",students[i].name);
        printf("Maths: ");
        scanf("%d",students[i].maths);
        printf("Physics: ");
        scanf("%d",students[i].physics);
        printf("Chemistry: ");
        scanf("%d",students[i].chemistry);
        printf("CS: ");
        scanf("%d",students[i].cs);
    }
}


void calculateTotalAndAverage(int n, Student students[]){
    for(int i = 0 ; i < n ; i++){
        students[i].totalMarks = 0;
        students[i].totalMarks += (students[i].maths + students[i].physics + students[i].chemistry + students[i].cs);
        students[i].percentage = (students[i].totalMarks / 400.0) * 100;
        if (students[i].percentage >= 90){
            students[i].grade = 'A';
        } else if (students[i].percentage >= 75 && students[i].percentage <= 89){
            students[i].grade = 'B';
        } else {
            students[i].grade = 'C';
        }
    }
}

void displayStudentDetails(int n, Student students[]){
    printf("--------------------------------------------------------------------------------------\n");
    printf("Student Details:\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("|%5s|%20s|%8s|%10s|%10s|\n", "ID","Name", "Total Marks", "Percentage", "Grade");
    for(int i = 0; i < n; i++) {
        printf("|%5d|%20s|%11d|%10.2f|%10c|\n", students[i].rollNo,
        students[i].name, students[i].totalMarks, students[i].percentage,
        students[i].grade);
    }
    printf("--------------------------------------------------------------------------------------\n");
}
void createfile(int n, Student students[]) {
    FILE *file;
    file = fopen("student.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for(int i = 0; i < n; i++) {
        fprintf(file, "%d %s %d %d %d %d\n", students[i].rollNo, students[i].name, students[i].maths, students[i].physics, students[i].chemistry, students[i].cs);
    }
    fclose(file);
}

void displayStudentDetailsUsingQueue(int n, Student students[]) {
    Queue que;
    QueueInit(&que);
    for (int i = 0; i < n; i++) {
        QueueEnqueue(&que, students[i]);
    }
    printf("Student Details displayed using Queue:\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("|%5s|%20s|%8s|%10s|%10s|\n", "ID", "Name", "Total Marks", "Percentage", "Grade");
    printf("--------------------------------------------------------------------------------------\n");
    while (!QueueEmpty(&que)) {
        Student student = QueueDequeue(&que);
        printf("|%5d|%20s|%11d|%10.2f|%10c|\n", student.rollNo,
               student.name, student.totalMarks, student.percentage,
               student.grade);
    }
    printf("--------------------------------------------------------------------------------------\n");
}
