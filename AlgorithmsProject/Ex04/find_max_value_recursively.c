/*
Recursively finding the max value in an array.
*/

#include <stdio.h>

int find_max_value_rec(int[], int);
void print_array(int[], int n);

int main()
{
    srand(time(NULL));
    int n = rand() % 20, array[n]; // Random array
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 69;
    }

    printf("array[]: ");
    print_array(array, n);

    printf("Max value: %d", find_max_value_rec(array, n));
    return 0;
}

int find_max_value_rec(int array[], int n)
{
    if (n == 1)
    {
        return array[0];
    }
    return array[n - 1] > find_max_value_rec(array, n - 1) ? array[n - 1] : find_max_value_rec(array, n - 1);
}

void print_array(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", array[i], (i < n - 1) ? ' ' : '\n');
    }
}