#include <stdio.h>
#include <string.h>

typedef struct {
    int rollNo;
    char name[50];
    int maths, physics, chemistry, cs;
    int totalMarks;
    float percentage;
    char grade[10];
} Student;

void readStudents(Student students[], int n);
void calculateGrades(Student students[], int n);
void displayStudents(Student students[], int n);
void saveStudents(Student students[],int n);

int main() {
    int n;
    Student students[100];
    printf("Enter number of students: ");
    scanf("%d", &n);
    readStudents(students, n);
    calculateGrades(students, n);
    displayStudents(students, n);
    saveStudents(students,n);
    return 0;
}

void readStudents(Student students[], int n) {
    printf("Enter details (Roll No, Name, Marks in 4 subjects):\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);
        printf("Name: ");
        scanf("%49s", students[i].name);  
        printf("Marks in 4 subjects:\n");
        printf("Maths: ");
        scanf("%d", &students[i].maths);
        printf("Physics: ");
        scanf("%d", &students[i].physics);
        printf("Chemistry: ");
        scanf("%d", &students[i].chemistry);
        printf("CS: ");
        scanf("%d", &students[i].cs);
    }
}

void calculateGrades(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        int sum = students[i].maths + students[i].physics + students[i].chemistry + students[i].cs;
        students[i].totalMarks = sum;
        students[i].percentage = (float)sum / 400.0 * 100;  
        if (students[i].percentage >= 90) {
            strcpy(students[i].grade, "A");
        } else if (students[i].percentage >= 80) {
            strcpy(students[i].grade, "B");
        } else if (students[i].percentage >= 70) {
            strcpy(students[i].grade, "C");
        } else if (students[i].percentage >= 60) {
            strcpy(students[i].grade, "D");
        } else if (students[i].percentage >= 50) {
            strcpy(students[i].grade, "E");
        } else {
            strcpy(students[i].grade, "F"); 
        }
    }
}

void displayStudents(Student students[], int n) {
    printf("\nStudent Report Card:\n");
    printf("---------------------------------------------------------------------------------------------------------------\n");
    printf("|%5s|%10s|%8s|%8s|%10s|%8s|%10s|%10s|%6s|\n"
        ,"Roll NO","Name","Maths","Physics","Chemistry","CS","Total Marks","Percentage","Grade");
    printf("---------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("|%7d|%10s|%8d|%8d|%10d|%8d|%11d|%10.2f|%6s|\n"
            ,students[i].rollNo,students[i].name,students[i].maths,students[i].physics
            ,students[i].chemistry,students[i].cs,students[i].totalMarks
            ,students[i].percentage,students[i].grade);
    }
}

void saveStudents(Student students[],int n){
    FILE* file = fopen("Student.txt","w");
    if(file == NULL){
        printf("Cannot create file\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file,"\nStudent Report Card:\n");
        fprintf(file,"---------------------------------------------------------------------------------------------------------------\n");
        fprintf(file,"|%5s|%10s|%8s|%8s|%10s|%8s|%10s|%10s|%6s|\n"
        ,"Roll NO","Name","Maths","Physics","Chemistry","CS","Total Marks","Percentage","Grade");
        fprintf(file,"---------------------------------------------------------------------------------------------------------------\n");
        fprintf(file,"|%7d|%10s|%8d|%8d|%10d|%8d|%11d|%10.2f|%6s|\n"
            ,students[i].rollNo,students[i].name,students[i].maths,students[i].physics
            ,students[i].chemistry,students[i].cs,students[i].totalMarks
            ,students[i].percentage,students[i].grade);
    }
    fclose(file);
}
