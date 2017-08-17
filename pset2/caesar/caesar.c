#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int ascii2alpha(char letter);
char alpha2ascii(int index, bool to_lower);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    // Get user's plaintxt and cypher key
    printf("plaintext:  ");
    string plaintxt = get_string();
    int key = atoi(argv[1]);

    // Create an alphabetical index
    int alpha_idx[26];
    for (int i = 0; i < 26; i++) { alpha_idx[i] = i; }

    // Store length of plaintxt array and init cyphertxt array
    int txtlen = strlen(plaintxt);  // For loop stop condition
    int cyphertxt[txtlen];  // Stores alpha index of the cyphered letter

    // Cypher the plaintxt
    printf("ciphertext: ");
    for (int i = 0; i < txtlen; i++)
    {
        if (!isalpha(plaintxt[i]))
        {
            // If char is not [a-Z], print and skip
            printf("%c", plaintxt[i]);
            continue;
        }
        // Find the alpha index of the cyphered letter and return ascii
        bool lower = islower(plaintxt[i]);
        cyphertxt[i] = (ascii2alpha(plaintxt[i]) + key) % 26;
        printf("%c", alpha2ascii(cyphertxt[i], lower));
    }
    printf("\n");
    return 0;
}

int ascii2alpha(char letter)
{
    // If ascii is lowercase, subtract 97 otherwise subtract 65
    return (islower(letter)) ? letter - 'a' : letter - 'A';
}

char alpha2ascii(int index, bool to_lower)
{
    // Simply reverse if going from alpha index to ascii
    return (to_lower) ? index + 'a' : index + 'A';
}
