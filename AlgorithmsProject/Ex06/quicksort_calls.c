/*
Checking quicksort recursive calls.
*/

#include <stdio.h>

void quicksort(int[], int, int);
void swap(int *, int *);
void print_array(int[], int);

int main()
{
    int v[] = {78, 21, 52, 33, 94}, w[] = {82, 31, 27, 18, 65, 40},
        v_length = sizeof(v) / sizeof(v[0]), w_length = sizeof(w) / sizeof(w[0]);

    printf("\narray v[]: \n");
    print_array(v, v_length);

    quicksort(v, 0, 4);

    printf("\n\nsorted array v[]: \n");
    print_array(v, v_length);

    puts("____________________________________________________");

    printf("\narray w[]: \n");
    print_array(w, w_length);

    quicksort(w, 0, 5);

    printf("\n\nsorted array w[]: \n");
    print_array(w, w_length);

    return 0;
}

void quicksort(int a[], int e, int d)
{
    int i = e, j = d, x = a[(i + j) / 2];

    printf("\ncalling quicksort(array, %d, %d)", e, d);

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

void swap(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void print_array(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    puts("\n");
}