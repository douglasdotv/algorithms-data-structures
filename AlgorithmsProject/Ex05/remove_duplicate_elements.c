/*
Removing duplicate elements from an array.
*/

#include <stdio.h>

int remove_duplicates(int[], int n);
void print_array(int[], int n);

int main()
{
    int array[10] = {2, 2, 2, 1, 1, 1, 1, 3, 4, 4};
    printf("Array with duplicate elements: \n");
    print_array(array, 10);
    printf("Removing duplicate elements: \n");
    print_array(array, 10 - remove_duplicates(array, 10));
}

int remove_duplicates(int array[], int n) // Will remove duplicate elements AND return the amount of removed elements.
{
    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[i] == array[j])
            {
                for (int k = j; k < n; k++)
                {
                    array[k] = array[k + 1];
                }
                j--;
                n--;
                counter++;
            }
        }
    }
    
    return counter;
}

void print_array(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", array[i], (i < n - 1) ? ' ' : '\n');
    }
}