#include <stdio.h>

struct Marks
{
    int maths;
    int science;
    int english;
};

struct Student
{
    int roll_no;
    char name[50];
    struct Marks marks;
};

int main()
{
    struct Student students[5];
    float avgMarks;

    for (int i = 0; i < 5; i++)
    {
        printf("Enter roll number: ");
        scanf("%d", &students[i].roll_no);
        printf("Enter name: ");
        scanf("%s", students[i].name);
        printf("Enter marks for maths, science, and english: ");
        scanf("%d %d %d", &students[i].marks.maths, &students[i].marks.science, &students[i].marks.english);
    }

    for (int i = 0; i < 5; i++)
    {
        avgMarks = (students[i].marks.maths + students[i].marks.science + students[i].marks.english) / 3.0;
        printf("Student: %s, Roll No: %d, Average Marks: %.2f\n", students[i].name, students[i].roll_no, avgMarks);
    }

    return 0;
}
