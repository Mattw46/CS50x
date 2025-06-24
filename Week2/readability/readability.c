#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int getLetters(string text);
int getWords(string text);
int getSentences(string text);
int calculateReadability(int letters, int sentences, int words);

int main(void)
{
    int grade = 0;

    string text = get_string("Text: ");

    int letters = getLetters(text);
    int sentences = getSentences(text);
    int words = getWords(text);

    // calculate averages
    grade = calculateReadability(letters, sentences, words);

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}

int getLetters(string text)
{
    int letterCount = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letterCount++;
        }
    }
    return letterCount;
}

int getWords(string text)
{
    int wordCount = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            wordCount++;
        }
        else if (text[i] == '!' || text[i] == '.' || text[i] == '?' || text[i] == ',')
        {
            wordCount++;
            if (i + 1 <= strlen(text) && text[i + 1] == ' ')
            {
                // skip over space after
                i++;
            }
        }
    }
    return wordCount;
}

int getSentences(string text)
{
    int sentenceCount = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentenceCount++;
        }
    }
    return sentenceCount;
}

int calculateReadability(int letters, int sentences, int words)
{
    float l = ((float) letters / (float) words) * 100;
    float s = ((float) sentences / (float) words) * 100;
    return round((0.0588 * l) - (0.296 * s) - 15.8);
}

