#include <cs50.h>
#include <stdio.h>

void print_pyramid(int n);
void print_spaces(int n);
void print_hashes(int n);

int main(void)
{
    int height;
    do
    {
        printf("Height: ");
        height = get_int();
    }
    while (height < 0 || height > 23);
    print_pyramid(height);
}

void print_pyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        int hashes = 2 + i;
        int spaces = n + 1 - hashes;
        print_spaces(spaces);
        print_hashes(hashes); printf("\n");
    }
}

void print_spaces(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void print_hashes(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}
