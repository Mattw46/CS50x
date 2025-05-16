#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int size = 0;
    do
    {
        size = get_int("Enter a number ");
    }
    while(size <= 0);
    int current = size - 1;
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            if (y < current)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        current--;
        printf("\n");
    }
}
