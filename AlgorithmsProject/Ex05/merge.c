/*
Given two arrays a and b, print another sorted array containing all elements from a and b.
*/

#include <stdio.h>
#include <stdbool.h>

void optimized_bubble_sort(int[], int);
void merge(int[], int, int, int);
void print_array(int[], int);
void swap(int *, int *);

int main()
{
    srand(time(NULL));
    int m = rand() % 10 + 1, n = rand() % 10 + 1, a[m], b[n]; // Random arrays a[] (length m) and b[] (length n)
    for (int i = 0; i < m; i++)
    {
        a[i] = rand() % 69;
    }
    for (int i = 0; i < n; i++)
    {
        b[i] = rand() % 69;
    }

    printf("\na[]: \n");
    print_array(a, m);
    printf("a[] (sorted): \n");
    optimized_bubble_sort(a, m);
    print_array(a, m);

    printf("\nb[]: \n");
    print_array(b, n);
    printf("b[] (sorted): \n");
    optimized_bubble_sort(b, n);
    print_array(b, n);

    printf("\nMerging a[] and b[] into a new array c[]:\n");
    int c[m + n];
    for (int i = 0; i < m; i++)
    {
        c[i] = a[i];
    }
    for (int i = m; i < m + n; i++)
    {
        c[i] = b[i - m];
    }
    merge(c, 0, m, m + n);
    print_array(c, m + n);
    puts("");
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

void merge(int array[], int low, int checkpoint, int high)
{
    int i = low, j = checkpoint, k = 0, a = checkpoint, b = high, temp_array[high - low];
    while (i < a && j < b)
    {
        if (array[i] < array[j])
        {
            temp_array[k++] = array[i++];
        }
        else
        {
            temp_array[k++] = array[j++];
        }
    }
    while (i < a)
    {
        temp_array[k++] = array[i++];
    }
    while (j < b)
    {
        temp_array[k++] = array[j++];
    }

    for (int i = low; i < high; i++)
    {
        array[i] = temp_array[i - low];
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