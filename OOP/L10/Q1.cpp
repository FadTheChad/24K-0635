#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Student {
    int id;
    string name;
    float gpa;
};

Student inputStudent() {
    Student s;
    cout << "Enter ID: ";
    cin >> s.id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter GPA: ";
    cin >> s.gpa;
    return s;
}

void writeStudentsToFile(const vector<Student>& students) {
    ofstream fout("students.txt", ios::out);
    for (const Student& s : students) {
        fout << s.id << " " << s.name << " " << s.gpa << endl;
    }
    fout.close();
}

void appendStudentToFile(const Student& s) {
    ofstream fout("students.txt", ios::app);
    fout << s.id << " " << s.name << " " << s.gpa << endl;
    fout.close();
}

void readAndDisplayStudents() {
    ifstream fin("students.txt");
    Student s;
    cout << "\n--- Student Records ---\n";
    while (fin >> s.id) {
        fin >> ws;
        getline(fin, s.name, ' ');
        fin >> s.gpa;
        cout << "ID: " << s.id << ", Name: " << s.name << ", GPA: " << s.gpa << endl;
    }
    fin.close();
}

int main() {
    vector<Student> students;

    cout << "Enter data for 5 students:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "Student " << i + 1 << ":\n";
        students.push_back(inputStudent());
    }

    writeStudentsToFile(students);

    cout << "\nEnter 1 additional student to append:\n";
    Student extra = inputStudent();
    appendStudentToFile(extra);

    // 4. Read and display all records
    readAndDisplayStudents();

    return 0;
}
