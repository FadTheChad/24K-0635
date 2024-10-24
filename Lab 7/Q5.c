#include <stdio.h>

int main()
{
    char str[100];
    char reversed[100];
    int length = 0, i, is_palindrome = 1;

    printf("Enter a string: ");
    gets(str);

    while (str[length] != '\0')
    {
        length++;
    }

    for (i = 0; i < length; i++)
    {
        reversed[i] = str[length - 1 - i];
    }
    reversed[length] = '\0';

    for (i = 0; i < length; i++)
    {
        if (str[i] != reversed[i])
        {
            is_palindrome = 0;
            break;
        }
    }

    if (is_palindrome)
    {
        printf("Palindrome");
    }
    else
    {
        printf("Not palindrome.\n");
    }

    return 0;
}
