#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream fout("data.txt");
    fout << "AI is the future. AI will transform the world. Embrace AI now.";
    fout.close();

    string searchWord, replacementWord;
    cout << "Enter search word: ";
    cin >> searchWord;
    cout << "Enter replacement word: ";
    cin >> replacementWord;

    fstream file("data.txt", ios::in | ios::out);
    string content;
    char ch;
    streampos pos;
    
    while (file.get(ch)) {
        if (ch == searchWord[0]) {  // Start comparing if the first character matches
            pos = file.tellg();  // Save the position where the word begins
            string temp;
            temp += ch;  // Add first character to temp

            // Read the rest of the characters in searchWord
            for (int i = 1; i < searchWord.length(); ++i) {
                char next;
                if (file.get(next)) {
                    temp += next;
                } else {
                    break;
                }
            }

            // If the word matches, replace it
            if (temp == searchWord) {
                // Move write pointer to the start of the found word
                file.seekp(pos - (streamoff)1); 

                // Write the replacement word
                file.write(replacementWord.c_str(), replacementWord.length());

                // If the replacement is shorter, pad with spaces
                if (replacementWord.length() < searchWord.length()) {
                    int diff = searchWord.length() - replacementWord.length();
                    for (int i = 0; i < diff; ++i) {
                        file.put(' ');  // Padding with spaces
                    }
                }

                // After writing, move the read pointer ahead to avoid re-reading the replaced word
                file.seekg(pos + (streamoff) searchWord.length());
            }
        }
    }

    // Reset file pointers to the beginning
    file.clear();   // Clear EOF flag
    file.seekg(0);  // Move read pointer to the start
    
    // Print the updated content of the file
    cout << "\n--- Updated File Content ---\n";
    while (getline(file, content)) {
        cout << content << endl;
    }

    file.close();
    return 0;
}
