#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin1("chapter1.txt");
    ifstream fin2("chapter2.txt");
    ofstream fout("book.txt", ios::app);

    string line;
    while (getline(fin1, line)) {
        fout << line << endl;
    }
    fout << endl;
    while (getline(fin2, line)) {
        fout << line << endl;
    }

    fin1.close();
    fin2.close();
    fout.close();

    ifstream fin("book.txt");
    cout << "\n--- Book Contents ---\n";
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();

    return 0;
}
