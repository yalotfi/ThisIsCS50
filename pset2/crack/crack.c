#define _XOPEN_SOURCE
#include <unistd.h>
#include <crypt.h>
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("please provide hashed password\n");
        return 1;
    }
    printf("%c%c\n", argv[1][0], argv[1][1]);
    string salt = argv[1][0] + argv[1][1];
    printf("Hash: %s\nSalt: %s\n", argv[1], salt);
    string password = crypt("rofl", salt);
    printf("Password: %s\n", password);
    return 0;
}