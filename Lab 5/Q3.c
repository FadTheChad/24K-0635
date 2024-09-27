#include <stdio.h>

int main() {
    char coffeeType;
    char sizeInput, manualInput;
    int isDouble = 0, isManual = 0;

    printf("Welcome to the Coffee Machine\n");
    printf("Enter coffee type (B for Black, W for White): ");
    scanf(" %c", &coffeeType);

    printf("Is the cup size double? (y/n): ");
    scanf(" %c", &sizeInput);
    isDouble = (sizeInput == 'y' || sizeInput == 'Y') ? 1 : 0;

    printf("Is the coffee manual? (y/n): ");
    scanf(" %c", &manualInput);
    isManual = (manualInput == 'y' || manualInput == 'Y') ? 1 : 0;

    switch(coffeeType) {
        case 'W':
        case 'w':
            if (isManual)
                printf("Manual Mode: You will be instructed to perform each step manually.\n");

            int waterTime = 15;
            int sugarTime = 15;
            int mix1Time = 20;
            int coffeeTime = 2;
            int milkTime = 4;
            int mix2Time = 20;
        
            if (isDouble) {
                waterTime *= 1.5;
                sugarTime *= 1.5;
                mix1Time *= 1.5;
                coffeeTime *= 1.5;
                milkTime *= 1.5;
                mix2Time *= 1.5;
            }
        
            printf("Instructions for White Coffee:\n");
            printf("1. Put water (time: %d mins)\n", waterTime);
            printf("2. Add sugar (time: %d mins)\n", sugarTime);
            printf("3. Mix well (time: %d mins)\n", mix1Time);
            printf("4. Add coffee (time: %d mins)\n", coffeeTime);
            printf("5. Add milk (time: %d mins)\n", milkTime);
            printf("6. Mix well (time: %d mins)\n", mix2Time);
        
            int totalTime = waterTime + sugarTime + mix1Time + coffeeTime + milkTime + mix2Time;
            printf("Total preparation time: %d mins\n\n", totalTime);
          
            break;
        case 'B':
        case 'b':
            if (isManual)
                printf("Manual Mode: You will be instructed to perform each step manually.\n");

            int waterTime = 20;
            int sugarTime = 20;
            int mix1Time = 25;
            int coffeeTime = 15;
            int mix2Time = 25;
        
            if (isDouble) {
                waterTime *= 1.5;
                sugarTime *= 1.5;
                mix1Time *= 1.5;
                coffeeTime *= 1.5;
                mix2Time *= 1.5;
            }
        
            printf("Instructions for Black Coffee:\n");
            printf("1. Put water (time: %d mins)\n", waterTime);
            printf("2. Add sugar (time: %d mins)\n", sugarTime);
            printf("3. Mix well (time: %d mins)\n", mix1Time);
            printf("4. Add coffee (time: %d mins)\n", coffeeTime);
            printf("5. Mix well (time: %d mins)\n", mix2Time);
        
            int totalTime = waterTime + sugarTime + mix1Time + coffeeTime + mix2Time;
            printf("Total preparation time: %d mins\n\n", totalTime);
          
            break;
        default:
            printf("Invalid coffee type!\n");
    }

    return 0;
}
