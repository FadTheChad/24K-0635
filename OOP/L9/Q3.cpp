#include <iostream>
#include "Q3_Book.hpp"

int main()
{
    Book book("The C++ Programming Language", "Bjarne Stroustrup", "978-0321563842");

    std::cout << "Title: " << book.getTitle() << std::endl;
    std::cout << "Author: " << book.getAuthor() << std::endl;
    std::cout << "ISBN: " << book.getISBN() << std::endl;

    return 0;
}