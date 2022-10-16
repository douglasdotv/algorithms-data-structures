/*
Beecrowd 2534 – General Exam – https://www.beecrowd.com.br/judge/pt/problems/view/2534
(No time limit restrictions)
*/

#include <stdio.h>

void quicksort_descending_order(int[], int, int);
void swap(int *, int *);

int main()
{
    int n, q, rank, x;

    do
    {
        scanf("%d %d", &n, &q);
        int nota[n];

        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &nota[i]);
        }

        quicksort_descending_order(nota, 0, n - 1);
        
        int counter = 1;
        while (counter <= q)
        {
            scanf("%d", &rank);
            printf("%d\n", nota[rank - 1]);
            counter++;
        }
    } while (scanf("%d", &x) == 1);

    return 0;
}

void quicksort_descending_order(int a[], int e, int d)
{
    int i = e, j = d, x = a[(i + j) / 2];

    do
    {
        while (a[i] > x)
        {
            i++;
        }
        while (a[j] < x)
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
        quicksort_descending_order(a, e, j);
    }
    
    if (i < d)
    {
        quicksort_descending_order(a, i, d);
    }
}

void swap(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}