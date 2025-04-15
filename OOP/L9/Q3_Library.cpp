#include "Q3_Library.hpp"
#include <iostream>

Library::Library(int initialCapacity)
    : books(new Book *[initialCapacity]), bookCount(0), capacity(initialCapacity) {}

Library::~Library()
{
    for (int i = 0; i < bookCount; i++)
    {
        delete books[i];
    }
    delete[] books;
}

void Library::addBook(const Book &book)
{
    if (bookCount == capacity)
    {
        capacity *= 2;
        Book **newBooks = new Book *[capacity];
        for (int i = 0; i < bookCount; i++)
        {
            newBooks[i] = books[i];
        }
        delete[] books;
        books = newBooks;
    }
    books[bookCount++] = new Book(book);
}

bool Library::removeBook(const string &isbn)
{
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i]->getISBN() == isbn)
        {
            delete books[i];
            for (int j = i; j < bookCount - 1; j++)
            {
                books[j] = books[j + 1];
            }
            bookCount--;
            return true;
        }
    }
    return false;
}

Book *Library::searchBook(const string &isbn)
{
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i]->getISBN() == isbn)
        {
            return books[i];
        }
    }
    return nullptr;
}

void Library::displayAllBooks() const
{
    for (int i = 0; i < bookCount; i++)
    {
        cout << "Title: " << books[i]->getTitle()
             << ", Author: " << books[i]->getAuthor()
             << ", ISBN: " << books[i]->getISBN() << endl;
    }
}