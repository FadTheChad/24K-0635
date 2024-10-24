#include <stdio.h>

int main()
{
    char str[50];

    int a = 0, e = 0, i = 0, o = 0, u = 0;

    printf("Enter: ");
    gets(str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        switch (str[i])
        {
        case 'A':
        case 'a':
            a++;
            break;
        case 'E':
        case 'e':
            e++;
            break;
        case 'I':
        case 'i':
            i++;
            break;
        case 'O':
        case 'o':
            o++;
            break;
        case 'U':
        case 'u':
            u++;
            break;
        }
    }
    printf("A: %d\n", a);
    printf("E: %d\n", e);
    printf("I: %d\n", i);
    printf("O: %d\n", o);
    printf("U: %d\n", u);
}