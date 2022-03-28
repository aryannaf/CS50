#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Verify there is one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Verify each character in argv[1] is a digit
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // Prompt user for plaintext
    string p = get_string("plaintext: ");

    // Convert the key from a string to an integer
    int k = atoi(argv[1]);
    printf("ciphertext: ");

    // Obtain the ciphertext by rotating each character that is a letter
    for (int i = 0; i < strlen(p); i++)
    {
        if (isupper(p[i]))
        {
            printf("%c", (((p[i] - 65) + k) % 26) + 65);
        }
        else if (islower(p[i]))
        {
            printf("%c", (((p[i] - 97) + k) % 26) + 97);
        }
        else
        {
            printf("%c", (p[i]));
        }
    }
    printf("\n");
}