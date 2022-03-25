#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long n;
    do
    {
        n = get_long("Number: ");
    }
    while (n < 0);

// Multiply every other digit by 2, starting from the second last digit
    int digit2, digit4, digit6, digit8, digit10, digit12, digit14, digit16;
    digit2 = ((n % 100) / 10) * 2;
    digit4 = ((n % 10000) / 1000) * 2;
    digit6 = ((n % 1000000) / 100000) * 2;
    digit8 = ((n % 100000000) / 10000000) * 2;
    digit10 = ((n % 10000000000) / 1000000000) * 2;
    digit12 = ((n % 1000000000000) / 100000000000) * 2;
    digit14 = ((n % 100000000000000) / 10000000000000) * 2;
    digit16 = ((n % 10000000000000000) / 1000000000000000) * 2;

// Add each digit together
    digit2 = (digit2 % 100 / 10) + (digit2 % 10);
    digit4 = (digit4 % 100 / 10) + (digit4 % 10);
    digit6 = (digit6 % 100 / 10) + (digit6 % 10);
    digit8 = (digit8 % 100 / 10) + (digit8 % 10);
    digit10 = (digit10 % 100 / 10) + (digit10 % 10);
    digit12 = (digit12 % 100 / 10) + (digit12 % 10);
    digit14 = (digit14 % 100 / 10) + (digit14 % 10);
    digit16 = (digit16 % 100 / 10) + (digit16 % 10);

    int sum1 = digit2 + digit4 + digit6 + digit8 + digit10 + digit12 + digit14 + digit16;

// Identify the rest of the card's digits that were not previously multiplied
    int digit1, digit3, digit5, digit7, digit9, digit11, digit13, digit15;
    digit1 = (n % 10);
    digit3 = ((n % 1000) / 100);
    digit5 = ((n % 100000) / 10000);
    digit7 = ((n % 10000000) / 1000000);
    digit9 = ((n % 1000000000) / 100000000);
    digit11 = ((n % 100000000000) / 10000000000);
    digit13 = ((n % 10000000000000) / 1000000000000);
    digit15 = ((n % 1000000000000000) / 100000000000000);

    int sum2 = digit1 + digit3 + digit5 + digit7 + digit9 + digit11 + digit13 + digit15;
    int sum = sum1 + sum2;

// If the last digit of the sum is not 0, print INVALID
    if ((sum % 10) != 0)
    {
        printf("INVALID\n");
        return 0;
    }
// Identify the number of digits in the given card number
    int length = 0;
    long amex = n;
    long mastercard = n;
    long visa = n;
    while (n > 0)
    {
        n /= 10;
        length++;
    }
// Check if the card number is AMEX
    while (amex >= 10000000000000)
    {
        amex /= 10000000000000;
    }
    if ((amex == 34 || amex == 37) && length == 15)
    {
        printf("AMEX\n");
        return 0;
    }
// Check if the card number is MASTERCARD
    while (mastercard >= 100000000000000)
    {
        mastercard /= 100000000000000;
    }
    if ((mastercard == 51 || mastercard == 52 || mastercard == 53 || mastercard == 54 || mastercard == 55) && length == 16)
    {
        printf("MASTERCARD\n");
        return 0;
    }
    // Check if the card number is VISA
    while (visa >= 10)
    {
        visa /= 10;
    }
    if (visa == 4 && (length == 13 || length == 16))
    {
        printf("VISA\n");
        return 0;
    }
    else
    {
        printf("INVALID\n");
    }
}