/*
Reversing an array.
*/

#include <stdio.h>

void reverse_array(int[], int);
void print_array(int[], int n);

int main()
{
    srand(time(NULL));
    int n = rand() % 10 + 1, array[n]; // Random array
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 69;
    }

    printf("Random array[]: \n");
    print_array(array, n);

    reverse_array(array, n);
    return 0;
}

void reverse_array(int array[], int n)
{
    int temp;
    for (int i = 0; i < n / 2; i++)
    {
        temp = array[i];
        array[i] = array[n - i - 1];
        array[n - i - 1] = temp;
    }
    printf("Reversed array[]: \n");
    print_array(array, n);
}

void print_array(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", array[i], (i < n - 1) ? ' ' : '\n');
    }
}