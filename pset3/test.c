#include <stdio.h>
#include <stdbool.h>

void sort(int values[], int n);
bool search(int value, int values[], int n);
bool binary_search(int target, int left, int right, int array[]);

int main(void)
{
    // Initialize
    int target = 12;
    int n = 11;
    int array[] = {10, 3, 5, 1, 7, 2, 9, 4, 8, 11, 6};
    printf("Target: %i\nLength: %i\n", target, n);

    // Test Sorting
    sort(array, n);
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");

    // Test Searching
    bool found = search(target, array, n);
    (found) ? printf("Target present in array\n")
            : printf("Target is not present in array\n");
}

bool search(int value, int values[], int n)
{
    // Implement binary search recursively starting from 0 to n
    int left = 0, right = n;
    return binary_search(value, left, right, values);
}

bool binary_search(int target, int left, int right, int array[])
{
    // So long as right index exceeds or equals left index, search array
    if (right >= left)
    {
        // Calculate middle index given left and right indexes
        int mid = left + (right - left) / 2;
        printf("%i\n", mid);
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

void sort(int values[], int n)
{
    // Must be O(n^2): Bubble-Sort Time!
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