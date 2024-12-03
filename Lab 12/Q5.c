#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int main() {
    int n;
    char *arr, *studentId, *temp;

    printf("Enter total number of characters for your name: ");
    scanf("%d", &n);
    n++;

    arr = (char*)malloc(n * sizeof(char));
    getchar();
    printf("Enter your full name: ");
    gets(arr);

    studentId = (char*)malloc(8 * sizeof(char));
    printf("Enter your student ID: ");
    gets(studentId);

    temp = (char*)malloc((n + 8) * sizeof(char));
    
    strcpy(temp, studentId);
    strcat(temp, arr);

    strcpy(arr, temp);

    free(temp);

    printf("Updated string: %s\n", arr);

    free(arr);
    free(studentId);

    return 0;
}
