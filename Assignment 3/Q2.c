#include <stdio.h>
#include <string.h>

struct Player
{
    int ballScores[12];
    char playerName[50];
    int totalScore;
};

int validateScore(int score)
{
    return (score >= 0 && score <= 6);
}

void playGame(struct Player *player)
{
    int score;
    printf("Enter scores for player %s:\n", player->playerName);
    player->totalScore = 0;

    for (int i = 0; i < 12; i++)
    {
        printf("Enter score for ball %d (0-6): ", i + 1);
        scanf("%d", &score);

        if (validateScore(score))
        {
            player->ballScores[i] = score;
            player->totalScore += score;
        }
        else
        {
            printf("Invalid score! Ball %d is a dot ball.\n", i + 1);
            player->ballScores[i] = 0;
        }
    }
}

void findWinner(struct Player player1, struct Player player2)
{
    if (player1.totalScore > player2.totalScore)
    {
        printf("%s wins with a score of %d!\n", player1.playerName, player1.totalScore);
    }
    else if (player1.totalScore < player2.totalScore)
    {
        printf("%s wins with a score of %d!\n", player2.playerName, player2.totalScore);
    }
    else
    {
        printf("It's a tie! Both players scored %d.\n", player1.totalScore);
    }
}

void displayMatchScoreboard(struct Player player1, struct Player player2)
{
    printf("\n----- Match Scoreboard -----\n");

    printf("\nPlayer: %s\n", player1.playerName);
    printf("Ball Scores: ");
    for (int i = 0; i < 12; i++)
    {
        printf("%d ", player1.ballScores[i]);
    }
    printf("\nTotal Score: %d\n", player1.totalScore);
    printf("Average Score: %.2f\n", player1.totalScore / 12.0);

    printf("\nPlayer: %s\n", player2.playerName);
    printf("Ball Scores: ");
    for (int i = 0; i < 12; i++)
    {
        printf("%d ", player2.ballScores[i]);
    }
    printf("\nTotal Score: %d\n", player2.totalScore);
    printf("Average Score: %.2f\n", player2.totalScore / 12.0);
}

int main()
{
    struct Player player1, player2;

    printf("Enter Player 1 name: ");
    gets(player1.playerName);

    printf("Enter Player 2 name: ");
    gets(player2.playerName);

    playGame(&player1);
    playGame(&player2);

    displayMatchScoreboard(player1, player2);
    findWinner(player1, player2);

    return 0;
}
