#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 20000
#define WORD_SIZE 100

void replaceWordInfile(const char *filename, const char *target, const char *replacement)
{
    FILE *file = fopen(filename, "r");
    if (!file)
        return;

    char ch;
    char tempWord[WORD_SIZE];
    int wordLen = 0;
    int targetLen = strlen(target);
    int replacementLen = strlen(replacement);
    char newContent[BUFFER_SIZE] = "";

    while (ch = fgetc(file))
    {
        if (ch != ' ' && ch != '\n' && ch != '\t' && ch != EOF)
        {
            if (wordLen < WORD_SIZE - 1)
            {
                tempWord[wordLen++] = ch;
                tempWord[wordLen] = '\0';
            }
        }
        else
        {
            if (wordLen > 0 && strcmp(tempWord, target) == 0)
            {
                strcat(newContent, replacement);
            }
            else
            {
                strcat(newContent, tempWord);
            }
            if (ch == ' ')
            {
                strcat(newContent, " ");
            }
            wordLen = 0;
            tempWord[0] = '\0';
        }
        if (ch == EOF)
            break;
    }

    fclose(file);

    file = fopen(filename, "w");
    if (!file)
        return;

    fwrite(newContent, 1, strlen(newContent), file);
    fclose(file);
}

int main()
{
    char filePath[100], target[50], replacement[50];

    printf("File name: ");
    scanf("%s", filePath);
    printf("Target word: ");
    scanf("%s", target);
    printf("Replacement word: ");
    scanf("%s", replacement);

    replaceWordInfile(filePath, target, replacement);

    return 0;
}
