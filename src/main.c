#include <stdio.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];
    FILE *file = fopen("students.bin", "wb");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Input for n students
    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &students[i].marks);
    }

    // Write the array to the binary file
    fwrite(students, sizeof(struct Student), n, file);
    fclose(file);
    printf("Data written to students.bin\n");

    // Reading from the file
    struct Student readStudents[n];
    file = fopen("students.bin", "rb");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fread(readStudents, sizeof(struct Student), n, file);
    fclose(file);

    // Display the students
    printf("Data read from students.bin:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Marks: %d\n", readStudents[i].name, readStudents[i].marks);
    }

    return 0;
}