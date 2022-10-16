/*
Sorting an array with bubblesort and selectionsort.
*/

#include <stdio.h>
#include <stdbool.h>

void optimized_bubble_sort(int[], int);
void selection_sort(int[], int);
void print_array(int[], int);
void swap(int *, int *);

int main()
{
    srand(time(NULL));
    int n = rand() % 69 + 1, array[n]; // Random array
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 69;
    }

    printf("\narray[]: \n");
    print_array(array, n);

    char c;
    printf("\nEnter 'b' for bubblesort or 's' for selectionsort: ");
    scanf("%c", &c);

    switch (c)
    {
    case 's':
        printf("\nChosen method: selectionsort\n");
        selection_sort(array, n);
        printf("\nSorted array[]: \n");
        print_array(array, n);
        puts("");
        break;
    case 'b':
        printf("\nChosen method: bubblesort\n");
        optimized_bubble_sort(array, n);
        printf("\nSorted array[]: \n");
        print_array(array, n);
        puts("");
        break;
    default:
        printf("Invalid input. Please enter 's' or 'b' (lower case)\n");
        break;
    }

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

void selection_sort(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[min_index])
            {
                min_index = j;
            }
        }
        swap(&array[i], &array[min_index]);
    }
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