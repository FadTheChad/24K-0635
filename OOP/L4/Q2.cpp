#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
    int id;
    string title;
    string author;
    bool availability;

public:
    Book(int i, string t, string a, bool avail)
    {
        id = i;
        title = t;
        author = a;
        availability = avail;
    }

    Book(int i, string t, string a)
    {
        id = i;
        title = t;
        author = a;
        availability = true;
    }

    Book()
    {
        id = 0;
        title = "";
        author = "";
        availability = true;
    };

    int getID() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool isAvailable() const { return availability; }

    void setAvailability(bool avail) { availability = avail; }

    void displayBook() const
    {
        cout << "ID: " << id << ", Title: " << title
             << ", Author: " << author << ", Available: "
             << (availability ? "Yes" : "No") << endl;
    }
};

class Library
{
private:
    Book *books;
    int bookCount;
    int capacity;

    void resizeArray()
    {
        int newCapacity = capacity == 0 ? 1 : capacity * 2;
        Book *newBooks = new Book[newCapacity];

        for (int i = 0; i < bookCount; i++)
        {
            newBooks[i] = books[i];
        }

        delete[] books;
        books = newBooks;
        capacity = newCapacity;
    }

public:
    Library()
    {
        capacity = 0;
        bookCount = 0;
        books = nullptr;
    }

    void addBook(int id, string title, string author, bool availability = true)
    {
        if (bookCount == capacity)
        {
            resizeArray();
        }

        books[bookCount] = Book(id, title, author, availability);
        bookCount++;
    }

    void borrowBook(int id)
    {
        for (int i = 0; i < bookCount; i++)
        {
            if (books[i].getID() == id)
            {
                if (books[i].isAvailable())
                {
                    books[i].setAvailability(false);
                    cout << "You have successfully borrowed: " << books[i].getTitle() << endl;
                    return;
                }
                else
                {
                    cout << "Sorry, the book is currently unavailable." << endl;
                    return;
                }
            }
        }
        cout << "Book with ID " << id << " not found!" << endl;
    }

    void returnBook(int id)
    {
        for (int i = 0; i < bookCount; i++)
        {
            if (books[i].getID() == id)
            {
                if (!books[i].isAvailable())
                {
                    books[i].setAvailability(true);
                    cout << "You have successfully returned: " << books[i].getTitle() << endl;
                    return;
                }
                else
                {
                    cout << "The book was not borrowed." << endl;
                    return;
                }
            }
        }
        cout << "Book with ID " << id << " not found!" << endl;
    }

    void displayAvailableBooks()
    {
        cout << "Available Books: " << endl;
        for (int i = 0; i < bookCount; i++)
        {
            if (books[i].isAvailable())
            {
                books[i].displayBook();
            }
        }
    }

    ~Library()
    {
        delete[] books;
    }
};

int main()
{
    Library lib;

    lib.addBook(1, "The Catcher in the Rye", "J.D. Salinger", true);
    lib.addBook(2, "To Kill a Mockingbird", "Harper Lee", true);
    lib.addBook(3, "1984", "George Orwell", true);

    lib.displayAvailableBooks();

    lib.borrowBook(2);

    lib.borrowBook(2);

    lib.returnBook(2);

    lib.displayAvailableBooks();

    return 0;
}
