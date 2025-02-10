#include <iostream>

using namespace std;

class Student
{
private:
    int studentId;
    string name;
    int age;
    char grade;

public:
    Student()
    {
        grade = 'N';
    }

    Student(int sId, string n, int a, char g)
    {
        studentId = sId;
        name = n;
        age = a;
        grade = g;
    }

    void promoteStudent()
    {
        grade--;

        if (grade < 'A')
            grade = 'A';

        if (grade == 'E')
            grade = 'D';
    }

    bool isEligibleForScholarship()
    {
        return grade == 'A';
    }

    void displayDetails()
    {
        cout << "Student ID: " << studentId << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main()
{
    Student s1(1, "Alice", 20, 'B');
    Student s2(2, "Bob", 21, 'A');
    Student s3;

    s1.displayDetails();
    s1.promoteStudent();
    s1.displayDetails();

    cout << endl;

    s2.displayDetails();
    cout << "Is eligible for scholarship: " << (s2.isEligibleForScholarship() ? "Yes" : "No") << endl;

    cout << endl;

    s3.displayDetails();
    s3.promoteStudent();
    s3.displayDetails();

    cout << endl;

    return 0;
}