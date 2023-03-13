/*
Sorting an array with mergesort and quicksort.
*/

#include <stdio.h>

void mergesort(int[], int, int);
void merge(int[], int, int, int);
void quicksort(int[], int, int);
void swap(int *, int *);
void print_array(int[], int);

int main(void)
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
    printf("\nEnter 'm' for mergesort or 'q' for quicksort: ");
    scanf("%c", &c);

    switch (c)
    {
    case 'm':
        printf("\nChosen method: mergesort\n");
        mergesort(array, 0, n);
        printf("\nSorted array[]: \n");
        print_array(array, n);
        puts("");
        break;
    case 'q':
        printf("\nChosen method: quicksort\n");
        quicksort(array, 0, n - 1);
        printf("\nSorted array: \n");
        print_array(array, n);
        puts("");
        break;
    default:
        printf("Invalid input. Please enter 'm' or 'q' (lower case).\n");
        break;
    }

    return 0;
}

void mergesort(int array[], int low, int high)
{
    if (high - low > 1)
    {
        int mid = (low + high) / 2;
        mergesort(array, low, mid);
        mergesort(array, mid, high);
        merge(array, low, mid, high);
    }
}

void merge(int array[], int l, int m, int r)
{
    int i = l, j = m, k = 0, a = m, b = r, temp_array[r - l];

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

    for (int i = l; i < r; i++)
    {
        array[i] = temp_array[i - l];
    }
}

void quicksort(int a[], int e, int d)
{
    int i = e, j = d, x = a[(i + j) / 2];

    do
    {
        while (a[i] < x)
        {
            i++;
        }
        while (a[j] > x)
        {
            j--;
        }
        if (i <= j)
        {
            swap(&a[i++], &a[j--]);
        }
    } while (i <= j);

    if (e < j)
    {
        quicksort(a, e, j);
    }

    if (i < d)
    {
        quicksort(a, i, d);
    }
}

void print_array(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", array[i], (i < n - 1) ? ' ' : '\n');
    }
}

void swap(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}