#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

void passwordGenerator();
void marksGrader();

int main() {
    int choice;
    do  {
        printf("\n============================\n");
        printf(" Multi-Utility C Project\n");
        printf("============================\n");
        printf("1. Password Generator\n");
        printf("2. Student Marks Grader\n");
        printf("3. Exit\n");
        printf("============================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                passwordGenerator();
                break;
            case 2:
                marksGrader();
                break;
            case 3:
                printf("Exiting....");
                break;
            default: 
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 3);
    return 0;
}
void passwordGenerator() {
    int length;
    printf("Enter the desired password Length: ");
    scanf("%d", &length);

    char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";
    int charCount = sizeof(characters) - 1;
    char password[length + 1];

    srand(time(0));
    for ( int i = 0; i < length; i++) {
        int index = rand() % charCount;
        password[i] = characters[index];   
    }
    password[length] = '\0';
    printf("Generated Password: %s\n", password);
}
void marksGrader() {
    int subjects; 
    printf("\nEnter number of subjects: ");
    scanf("%d", &subjects);

    float total = 0;
    float marks[subjects];
    for ( int i = 0; i < subjects; i++)  {
        while (1) {
            printf("Enter marks for subject %d: ", i + 1);

            if ( scanf("%f", &marks[i]) != 1) {
                printf("[X] Invalid input! Please enter a number.\n");
                while (getchar() != '\n');
                continue;
            } 
            if ( marks[i] < 0 || marks[i] > 100) {
                printf("[X] Invalid marks! Must be between 0 and 100.\n");
                continue;
            } 
            break;
        } total += marks[i];
    }
    float average = total / subjects;
    char grade;

    if ( average >= 90) {
        grade = 'A';
    } else if ( average >= 75) {
        grade = 'B';
    } else if ( average >= 60) {
        grade = 'C';
    } else if ( average >= 40) {
        grade = 'D';
    } else if ( average >= 0) {
        grade = 'F';
    }
    printf("\n Results:\n");
    printf("Total Marks: %.2f\n", total);
    printf("Average: %.2f%%\n", average);
    printf("Grade: %c\n", grade);
} 