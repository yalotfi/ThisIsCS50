/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

bool binary_search(int target, int left, int right, int array[]);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // Implement binary search recursively starting from 0 to n
    int left = 0, right = n;
    return binary_search(value, left, right, values);
}

/**
 * Performs binary search recursively.
 */
bool binary_search(int target, int left, int right, int array[])
{
    // So long as right index exceeds or equals left index, search array
    if (right >= left)
    {
        // Calculate middle index given left and right indexes
        int mid = left + (right - left) / 2;

        // If target equals middle element, we found the target
        if (array[mid] == target)
        {
            return true;
        }
        // If target is greater than mid value, it must be to the right
        else if (target > array[mid])
        {
            return binary_search(target, mid + 1, right, array);
        }
        // Otherwise, it must be to the left
        else
        {
            return binary_search(target, left, mid - 1, array);
        }
    }
    // At this point, we know target is not in array
    else
    {
        return false;
    }
}

/**
 * Implement Bubble Sort to organize n values in ascending order.
 */
void sort(int values[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (values[j] > values[j + 1])
            {
                // Swap
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
    return;
}
