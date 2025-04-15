#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "Q3_Book.hpp"

class Library
{
private:
    Book **books;
    int bookCount;
    int capacity;

public:
    Library(int initialCapacity = 10);
    ~Library();
    void addBook(const Book &book);
    bool removeBook(const string &isbn);
    Book *searchBook(const string &isbn);
    void displayAllBooks() const;
};

#endif