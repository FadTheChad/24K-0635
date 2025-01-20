/*
Q2: Design a C++ program to manage student marks. Allow the user to input
marks for students in three subjects (Mathematics, English, and Science). The
program should calculate the total marks, average marks, and display the grade
for each student. The user can specify the number of students and then input
the marks for each subject for each student. Finally, display the marks, total,
average, and grade for each student. Assume a grading system with the
following criteria:
    90 or above: Grade A
    80-89: Grade B
    70-79: Grade C
    60-69: Grade D
    Below 60: Grade F
*/

#include <iostream>

using namespace std;

typedef struct
{
    int maths;
    int eng;
    int sci;
} Student;

char calc_grade(int marks)
{
    if (marks >= 90)
        return 'A';
    else if (marks >= 80)
        return 'B';
    else if (marks >= 70)
        return 'C';
    else if (marks >= 60)
        return 'D';
    else
        return 'F';
}

int main()
{
    int n;

    cout << "Enter num of students: ";
    cin >> n;

    Student *students = new Student[n];

    cout << "\t==== STUDENT INPUT ====\n";
    for (int i = 0; i < n; i++)
    {
        cout << "STUDENT " << i + 1 << "\n";

        cout << "Enter marks (Maths): ";
        cin >> students[i].maths;

        cout << "Enter marks (English): ";
        cin >> students[i].eng;

        cout << "Enter marks (Science): ";
        cin >> students[i].sci;

        cout << "\n";
    }

    cout << "\t==== STUDENT RESULTS ====\n";
    for (int i = 0; i < n; i++)
    {
        cout << "STUDENT " << i + 1 << "\n";

        cout << "Maths: " << calc_grade(students[i].maths) << "\n";

        cout << "English: " << calc_grade(students[i].eng) << "\n";

        cout << "Science: " << calc_grade(students[i].sci) << "\n";

        int total = students[i].maths + students[i].eng + students[i].sci;

        cout << "Average: " << total / 3 << "\n";
        cout << "Total: " << total << "\n";

        cout << "\n";
    }
}