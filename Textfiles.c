#include <stdio.h>
#include <stdbool.h>

#define print(a,b,c,d,e,f,n) printf("%s %s %s %d %d %d %d\n", a,b,c,d,e,f,n)
#define scan_s(str) scanf("%s", str)
#define scan_d(num) scanf("%d", &num)

struct student {
    char surname[50];
    char name[50];
    char patronymic[50];
    int group;
    int mathematics;
    int physics;
    int chemistry;
};

void outputStudents(struct student students[], int count) {
    for (int j = 0; j < count; j++) {
        if (students[j].chemistry >= 3) {
            students[j].chemistry = students[j].chemistry - 1;
        }
    }
    
    for (int i = 0; i < count; i++) {
        print(
            students[i].surname,
            students[i].name,
            students[i].patronymic,
            students[i].group,
            students[i].mathematics,
            students[i].physics,
            students[i].chemistry);
    }
}

void inputStudents(struct student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter the student's last name: ");
        scan_s(students[i].surname);
        printf("Enter the student's name: ");
        scan_s(students[i].name);
        printf("Enter the student's middle name: ");
        scan_s(students[i].patronymic);
        printf("Enter the student's group: ");
        scan_d(students[i].group);
        printf("Enter the math score: ");
        scan_d(students[i].mathematics);
        printf("Enter a physics grade: ");
        scan_d(students[i].physics);
        printf("Enter a chemistry grade: ");
        scan_d(students[i].chemistry);
    }
}

void saveStudents(struct student students[], int count) {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %s %d %d %d %d\n",
            students[i].surname,
            students[i].name,
            students[i].patronymic,
            students[i].group,
            students[i].mathematics,
            students[i].physics,
            students[i].chemistry);
    }
    
    fclose(file);
}

void loadStudents(struct student students[], int count) {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fscanf(file, "%s %s %s %d %d %d %d",
            students[i].surname,
            students[i].name,
            students[i].patronymic,
            &students[i].group,
            &students[i].mathematics,
            &students[i].physics,
            &students[i].chemistry);
    }
    
    fclose(file);
}

int main() {
    int count = 0;
    printf("Enter the number of students: ");
    scanf("%d", &count);
    struct student students[count];
    
    inputStudents(students, count);
    outputStudents(students, count);
    
    saveStudents(students, count);
    printf("====Read from student.txt====\n");   
    struct student loadedStudents[count];
    loadStudents(loadedStudents, count);
    
    outputStudents(loadedStudents, count);
    
    return 0;
}
