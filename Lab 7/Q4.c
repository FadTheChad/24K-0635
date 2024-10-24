#include <stdio.h>

int main()
{
    char str[100];
    char *start, *end, temp;
    int length = 0;

    printf("Enter a string: ");
    gets(str);

    start = str;

    while (*start != '\0')
    {
        length++;
        start++;
    }

    printf("Length: %d\n", length);

    start = str;
    end = str + length - 1;

    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    printf("Reversed string: %s\n", str);

    return 0;
}
