#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function prototypes
bool is_valid_key(string key);
bool has_all_unique_letters(string key);
char substitute(char c, string key);

int main(int argc, string argv[])
{
    // Check for correct number of arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Validate the key
    if (!is_valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    // Iterate through each character of plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", substitute(plaintext[i], key));
    }

    printf("\n");
    return 0;
}

// Check if key is valid
bool is_valid_key(string key)
{
    int length = strlen(key);
    if (length != 26)
    {
        return false;
    }

    // Check that all characters are alphabetic
    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }

    return has_all_unique_letters(key);
}

// Ensure all letters in the key are unique (case-insensitive)
bool has_all_unique_letters(string key)
{
    bool seen[26] = {false};

    for (int i = 0; i < 26; i++)
    {
        char c = tolower(key[i]);
        int index = c - 'a';

        if (seen[index])
        {
            return false; // Duplicate found
        }

        seen[index] = true;
    }

    return true;
}

// Substitute character using key
char substitute(char c, string key)
{
    if (isalpha(c))
    {
        int index = tolower(c) - 'a';
        char sub = key[index];

        // Preserve case
        if (isupper(c))
        {
            return toupper(sub);
        }
        else
        {
            return tolower(sub);
        }
    }
    else
    {
        return c; // Non-alphabetical characters unchanged
    }
}
