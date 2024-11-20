#include <stdio.h>
#include <string.h>

typedef struct
{
    char title[20];
    char author[20];
    int publicationYear;
    float price;
} Book;

void display(Book books[], int n)
{
    printf("\nAll Books in the Library:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nTitle: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Publication Year: %d\n", books[i].publicationYear);
        printf("Price: %.2f\n", books[i].price);
    }
}

void searchByTitle(Book books[], int n, char title[])
{
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(books[i].title, title) == 0)
        {
            printf("\nBook found:\n");
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Publication Year: %d\n", books[i].publicationYear);
            printf("Price: %.2f\n", books[i].price);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("\nBook with title '%s' not found.\n", title);
    }
}

void searchByAuthor(Book books[], int n, char author[])
{
    int found = 0;
    printf("\nBooks by %s:\n", author);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(books[i].author, author) == 0)
        {
            printf("Title: %s\n", books[i].title);
            printf("Publication Year: %d\n", books[i].publicationYear);
            printf("Price: %.2f\n", books[i].price);
            found = 1;
        }
    }
    if (!found)
    {
        printf("No books found by %s.\n", author);
    }
}

int main()
{
    Book library[999];
    int n;
    printf("Enter the number of books: ");
    scanf("%d", &n);
    getchar(); // Consume the newline character left by scanf

    // Get book details from the user
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details for book %d:\n", i + 1);

        printf("Title: ");
        gets(library[i].title);

        printf("Author: ");
        gets(library[i].author);

        printf("Publication Year: ");
        scanf("%d", &library[i].publicationYear);

        printf("Price: ");
        scanf("%f", &library[i].price);
        getchar();
    }

    // Display all books
    display(library, n);

    // Search for a book by title
    char title[100];
    printf("\nEnter the title to search for: ");
    gets(title);
    searchByTitle(library, n, title);

    // List books by a specific author
    char author[100];
    printf("\nEnter the author to list books by: ");
    gets(author);
    searchByAuthor(library, n, author);

    return 0;
}
