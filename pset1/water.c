#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Minutes: ");
    int minutes = get_int();
    int ounces_per_min = 1.5 * 128;
    printf("Bottles: %i\n", ounces_per_min * minutes / 16);
}