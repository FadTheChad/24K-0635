#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using namespace std;

class Book
{
private:
    string title;
    string author;
    string ISBN;

public:
    Book(const string &t, const string &a, const string &isbn);
    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
};

#endif