#include <cs50.h>
#include <stdio.h>

bool check_card_number(long number);

int main(void)
{
    long number = get_long("number: ");
    int get_length(long number);
    int get_start_digits(long number, int digits);

    bool valid_card = check_card_number(number);
    if (!check_card_number(number))
    {
        printf("INVALID\n");
        return 0;
    }

    int length = get_length(number);
    int start_two = get_start_digits(number, 2);
    int start_one = get_start_digits(number, 1);

    if (length == 15 && (start_two == 34 || start_two == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (start_two >= 51 && start_two <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && start_one == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

bool check_card_number(long number)
{
    int total = 0;
    bool alternate = false;

    while (number > 0)
    {
        int current = number % 10;

        if (alternate)
        {
            current *= 2;
            if (current > 9)
            {
                // if over 9 get the last digit and 1 ie 18 is 1 + 8
                current = (current % 10) + 1;
            }
        }
        total += current;
        alternate = !alternate;
        number /= 10;
    }
    // if the last digit modulo 10 is 0 then true
    return (total % 10 == 0);
}

int get_length(long number)
{
    int length = 0;
    while (number > 0)
    {
        number /= 10;
        length++;
    }
    return length;
}

int get_start_digits(long number, int digits)
{
    while (number >= 10 && digits < get_length(number))
    {
        number /= 10;
    }
    if (digits == 2)
    {
        return number % 100;
    }
    else
    {
        return number % 10;
    }
}
