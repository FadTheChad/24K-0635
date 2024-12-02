#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getStr()
{
    char *input = malloc(1);
    strcpy(input, "");

    int i = 0;
    while (1)
    {
        char c;
        scanf("%c", &c);

        if (c == '\n')
            break;

        input = (char *)realloc(input, (i + 2));
        input[i++] = c;
        input[i] = '\0';
    }

    return input;
}

int validateEmail(char *email)
{
    int numOfAts = 0;
    int numOfDots = 0;

    if (email[0] == '\0')
        return 0;

    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@')
            numOfAts++;
        else if (email[i] == '.' && numOfAts == 1)
            numOfDots++;

        if (numOfAts > 1)
            return 0;
    }

    if (numOfDots == 0)
        return 0;

    return 1;
}

int main()
{
    char *email = getStr();

    printf("%s Email", validateEmail(email) ? "Valid" : "Invalid");
    free(email);
}