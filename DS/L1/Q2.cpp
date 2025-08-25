#include <iostream>
#include <string>
using namespace std;

class Exam {
private:
    string* studentName;
    string* examDate;
    int* score;

public:
    Exam(string name, string date, int s) {
        studentName = new string(name);
        examDate = new string(date);
        score = new int(s);
    }

    void setExam(string name, string date, int s) {
        *studentName = name;
        *examDate = date;
        *score = s;
    }

    void display() {
        cout << "Student Name: " << *studentName << endl;
        cout << "Exam Date   : " << *examDate << endl;
        cout << "Score       : " << *score << endl;
    }

    ~Exam() {
        delete studentName;
        delete examDate;
        delete score;
    }
};

int main() {
    Exam exam1("Fadil F.", "9/11/2025", 95);
    cout << "Original:" << endl;
    exam1.display();

    Exam exam2 = exam1;
    cout << "\nShallow Copy:" << endl;
    exam2.display();

    // This would change exam1 aswell, due to shallow copy and usage of pointers.
    exam2.setExam("Fadil F.", "1/2/2025", 85);

    cout << "Original (New) :" << endl;
    exam1.display();

    Exam exam2 = exam1;
    cout << "\nShallow Copy (New):" << endl;
    exam2.display();

    // We observe that both exam1 and exam2 change to the same values, due to the shallow copy and change in exam2. This is because both exam1 and exam2 objects have properties that share the same pointer.

    return 0;
}