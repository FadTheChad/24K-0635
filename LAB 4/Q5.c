#include <stdio.h>

int main() {
    char character;

    printf("Enter a character: ");
    scanf("%c", &character);

    if (character >= 'a' && character <= 'z') {
        printf("%c is a small alphabet.\n", character);
    }

    else if (character >= 'A' && character <= 'Z') {
        printf("%c is a capital alphabet.\n", character);
    }
    
    else if (character >= '0' && character <= '9') {
        printf("%c is a digit.\n", character);
    }
    
    else {
        printf("%c is a special character.\n", character);
    }

    return 0;
}
