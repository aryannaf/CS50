#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Verify there is only one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //Verify there are 26 non-repeating letters in the key
    string k = argv[1];
    for (int i = 0; i < strlen(k); i++)
    {
        if (!isalpha(k[i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    if (strlen(k) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < strlen(k); i++)
    {
        for (int j = i + 1; j < strlen(k); j++)
        {
            if (toupper(k[i]) == toupper(k[j]))
            {
                printf("Key must not repeat any character.\n");
                return 1;
            }
        }
    }

    // Prompt user for plaintext
    string p = get_string("plaintext: ");

    for (int i = 0; i < strlen(k); i++)
    {
        if (islower(k[i]))
        {
            k[i] = k[i] - 32;
        }
    }

    printf("ciphertext: ");

    for (int i = 0; i < strlen(p); i++)
    {
        if (isupper(p[i]))
        {
            int c = p[i] - 65;
            printf("%c", k[c]);
        }
        else if (islower(p[i]))
        {
            int c = p[i] - 97;
            printf("%c", k[c] + 32);
        }
        else
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");
    return 0;
}