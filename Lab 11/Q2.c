#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define INITIAL_CAPACITY 100

typedef struct
{
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int findWord(WordCount *wordCounts, int size, char *word)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(wordCounts[i].word, word) == 0)
        {
            return i;
        }
    }
    return -1;
}

void toLowerCase(char *word)
{
    for (int i = 0; word[i]; i++)
    {
        word[i] = tolower(word[i]);
    }
}

int main()
{
    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    WordCount *wordCounts = malloc(INITIAL_CAPACITY * sizeof(WordCount));
    int size = 0;
    int capacity = INITIAL_CAPACITY;

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%49s", word) != EOF)
    {
        toLowerCase(word);
        int index = findWord(wordCounts, size, word);
        if (index != -1)
        {
            wordCounts[index].count++;
        }
        else
        {
            if (size == capacity)
            {
                capacity *= 2;
                wordCounts = realloc(wordCounts, capacity * sizeof(WordCount));
            }
            strcpy(wordCounts[size].word, word);
            wordCounts[size].count = 1;
            size++;
        }
    }

    fclose(file);

    for (int i = 0; i < size; i++)
    {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    free(wordCounts);
    return 0;
}
