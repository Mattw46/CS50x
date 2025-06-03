#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int calculateScore(string word);
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    int player1Score, player2Score;

    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    player1Score = calculateScore(player1);
    player2Score = calculateScore(player2);

    if (player1Score > player2Score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player1Score < player2Score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

int calculateScore(string word)
{
    int score = 0;
    int length = strlen(word);

    for (int i = 0; i < length; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}
