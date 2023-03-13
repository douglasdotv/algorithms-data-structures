/*
Performing a binary search on a sorted array.
*/

#include <stdio.h>
#include <stdbool.h>

void optimized_bubble_sort(int[], int);
int binary_search(int[], int, int);
void print_array(int[], int n);
void swap(int *, int *);

int main(void)
{
    srand(time(NULL));
    int n = rand() % 69 + 1, a[n]; // Random array
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 69;
    }

    printf("\nRandom array a[]: ");
    print_array(a, n);
    printf("\nSorting a[]...\n");
    optimized_bubble_sort(a, n); // Sorting our array
    printf("\nSorted array a[]: ");
    print_array(a, n);

    int value;
    printf("\nNow, let's search for a value inside the array. Enter a value to be searched via binary search: ");
    scanf("%d", &value);
    printf("\nIs %d included in the array?\n", value);
    int index = binary_search(a, n, value); // Performing binary search
    index != -1 ? printf("\nYes, it is.\n(At index %d.)\n", index) : printf("\nNo. Sadly, it isn't.\n");

    return 0;
}

void optimized_bubble_sort(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}

int binary_search(int array[], int n, int value)
{
    int low = 0, high = n;

    do
    {
        int midpoint = low + (high - low) / 2;
        if (array[midpoint] == value)
        {
            return midpoint;
        }
        else if (array[midpoint] > value)
        {
            high = midpoint;
        }
        else
        {
            low = midpoint + 1;
        }
    } while (high > low);

    return -1;
}

void print_array(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", array[i], (i < n - 1) ? ' ' : '\n');
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}