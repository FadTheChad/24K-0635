#include "Q3_Book.hpp"

Book::Book(const string &t, const string &a, const string &isbn)
    : title(t), author(a), ISBN(isbn) {}

string Book::getTitle() const
{
    return title;
}

string Book::getAuthor() const
{
    return author;
}

string Book::getISBN() const
{
    return ISBN;
}