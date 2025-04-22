#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream fout("info.txt", ios::out);
    fout << "C++ is a powerful programming language.";
    fout.close();

    fstream file("info.txt", ios::in | ios::out);

    cout << "Initial get pointer: " << file.tellg() << endl;
    cout << "Initial put pointer: " << file.tellp() << endl;

    file.seekg(6);
    char word[9];
    file.read(word, 8);
    word[8] = '\0';
    cout << "Word read from position 6: " << word << endl;

    file.seekp(6);
    file.write("dynamic", 8);

    cout << "New get pointer: " << file.tellg() << endl;
    cout << "New put pointer: " << file.tellp() << endl;

    file.seekg(0);
    string line;
    getline(file, line);
    cout << "Updated file content: " << line << endl;

    file.close();
    return 0;
}
