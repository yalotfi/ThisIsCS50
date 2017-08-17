#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool check_char(int i, string char_array);  // Should I print char?
char capitalize(char c);  // Capitalizes char if it prints

int main(void)
{
    // Get user input
    string name_array = get_string();
    
    // If the first char is not a space, print it, otherwise skip it
    if (name_array[0] != ' ')
    {
        printf("%c", capitalize(name_array[0]));
    }
    
    // Beginingn from second char, iteratively check each element
    for (int i = 1, n = strlen(name_array); i < n; i++)
    {
        // Follow logical check for each element
        if (check_char(i, name_array))
        {
            printf("%c", capitalize(name_array[i]));
        }
    }
    printf("\n");  // Just to format based on the task
}

bool check_char(int i, string char_array)
{
    bool not_space = char_array[i] != ' ';
    bool lead_char = char_array[i - 1] == ' ';

    // Current char is NOT a space but the preceding char is
    return not_space && lead_char;
}

char capitalize(char c)
{
    // If char is lowercase, return the uppercase value else return unchanged
    return (c >= 97) ? (c - 32) : c;
}