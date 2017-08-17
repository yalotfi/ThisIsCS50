#include <stdio.h>  // C primitives
#include <cs50.h>  // CS50 Library: get_floats()
#include <math.h>  // Math Library: round()

int count_coins(int cents);  // Count number of coins dispensed
bool which_coin(int coin_value, int cents);  // Which coin should dispense?
int dollar_to_cent(float dollar);  // Convert from dollars to cents

int main(void)
{
    // Promt for user input
    float dollar_amount;  // Dollar denominated as type float
    do
    {
        printf("O hai! How much change is owed?\n");
        dollar_amount = get_float();
    }
    while (dollar_amount < 0);  // Keep asking if input is negative
    int cents = dollar_to_cent(dollar_amount);  // Casts cents to type int
    printf("%i\n", count_coins(cents));  // Count the coins
}

int count_coins(int cents)
{
    int coins = 0;  // Iterator
    int quarter = 25; int dime = 10;  // Each coin value
    int nickel = 5.0; int penny = 1;
    while (cents > 0)  // As long as change is owed:
    {
        if (which_coin(quarter, cents))
        {
            cents -= quarter;  // Decrement change owed by coin value.
            coins++;  // Count another dispensed coin
        }
        else if (which_coin(dime, cents))
        {
            cents -= dime;
            coins++;
        }
        else if (which_coin(nickel, cents))
        {
            cents -= nickel;
            coins++;
        }
        else
        {
            cents -= penny;
            coins++;
        }        
    }
    return coins;
}

bool which_coin(int value, int cents)
{
    /****
    If entire coin value goes into change owed OR
    if change owed divides into the coin value evenly
    return True, otherwise return False 
    ****/
    return value % cents == value || cents % value == 0;
}

int dollar_to_cent(float dollar)
{
    // Convert to cents and round float before casting to integer
    return round(dollar * 100);
}