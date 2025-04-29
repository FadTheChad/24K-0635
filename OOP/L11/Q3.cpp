#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;

class FileException : public exception {
protected:
    string message;
public:
    FileException(const string& msg = "A generic file error occurred") : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
    virtual ~FileException() noexcept {}
};

class FileNotFoundException : public FileException {
public:
    FileNotFoundException(const string& filename = "")
        : FileException("FileNotFoundException - Unable to locate the file: " + (filename.empty() ? "Unknown" : filename)) {}
};

class PermissionDeniedException : public FileException {
public:
    PermissionDeniedException(const string& filename = "")
        : FileException("PermissionDeniedException - You do not have permission to access this file.") {}
};

void readFile(const string& filename) {
    cout << "Attempting to open '" << filename << "'..." << endl;
    if (filename == "missing_file.txt") {
        throw FileNotFoundException(filename);
    } else if (filename == "restricted_area.txt") {
        throw PermissionDeniedException(filename);
    } else if (filename == "corrupted_file.txt") {
        throw FileException("FileException - There was an issue with the file.");
    } else {
        cout << "File '" << filename << "' opened successfully." << endl;
    }
}

int main() {
    string files[] = {"datafile.txt", "restricted_area.txt", "missing_file.txt", "corrupted_file.txt"};

    for (const string& file : files) {
        try {
            readFile(file);
        } catch (const FileNotFoundException& e) {
            cerr << "Error Specific to File: " << e.what() << endl;
        } catch (const PermissionDeniedException& e) {
            cerr << "Attempt to read '" << file << "': " << e.what() << endl; 
        } catch (const FileException& e) { 
            cerr << "General File Error: " << e.what() << endl;
        } catch (const exception& e) {
            cerr << "Caught Standard Exception: " << e.what() << endl;
        }
        cout << "--------------------" << endl;
    }

    return 0;
}
