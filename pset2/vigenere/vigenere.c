#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

char vigenere(char letter, char key);
int ascii2alpha(char letter);
char alpha2ascii(int index, bool to_lower);

int main(int argc, char *argv[])
{
    // Check that two args were passed
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }

    // Check that the second arg is only alphabetical chars
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }

    // Get user's plaintxt and key phrase
    printf("plaintext: ");
    string plaintxt = get_string();
    string key = argv[1];

    // Store key length to find shift of each letter
    int keylen = strlen(key);  // Length of key argument

    // Cipher the plaintxt:
    printf("ciphertext: ");
    for (int i = 0, j = 0, n = strlen(plaintxt); i < n; i++)
    {
        if (isalpha(plaintxt[i]))
        {
            // Apply vigenere's cipher to each plain letter
            printf("%c", vigenere(plaintxt[i], key[j % keylen]));

            // Only increment j when ciphering an alphabetical char
            j++;
        }
        else
        {
            // If char is not [a-Z], print and skip
            printf("%c", plaintxt[i]);
        }
    }
    printf("\n");
    return 0;
}

char vigenere(char letter, char key)
{
    // Store params of the cipher function
    int p_i = ascii2alpha(letter);  // Indexed position of plain letter
    int k_j = ascii2alpha(key);  // Indexed shift by k
    
    // Find alphabetical index of ciphered letter and return ascii
    int c_i = (p_i + k_j) % 26;
    return alpha2ascii(c_i, islower(letter));
}

int ascii2alpha(char letter)
{
    // If ascii is lowercase, subtract 97 otherwise subtract 65
    return (islower(letter)) ? letter - 'a' : letter - 'A';
}

char alpha2ascii(int index, bool to_lower)
{
    // Given casing, go from alpha index to ascii
    return (to_lower) ? index + 'a' : index + 'A';
}