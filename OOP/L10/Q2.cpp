#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string name, email, summary;
    int yearsOfExperience;

    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Email: ";
    getline(cin, email);
    cout << "Enter Years of Experience: ";
    cin >> yearsOfExperience;
    cin.ignore();
    cout << "Enter Summary: ";
    getline(cin, summary);

    ofstream fout("resume.txt", ios::trunc);
    fout << "Name: " << name << endl;
    fout << "Email: " << email << endl;
    fout << "Years of Experience: " << yearsOfExperience << endl;
    fout << "Summary: " << summary << endl;
    fout.close();

    ifstream fin("resume.txt");
    string line;
    cout << "\n--- Resume Contents ---\n";
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();

    return 0;
}
