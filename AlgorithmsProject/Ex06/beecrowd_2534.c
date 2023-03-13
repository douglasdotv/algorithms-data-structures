/*
Beecrowd 2534 – General Exam – https://www.beecrowd.com.br/judge/pt/problems/view/2534
*/

#include <stdio.h>

void quicksort_descending_order(int[], int, int);
void swap(int *, int *);

int main (void)
{
	int n, q, rank;

	while (scanf("%d %d", &n, &q) != EOF)
	{
		int notas[n];

		for (int i = 0; i < n; i++) {
			scanf("%d", &notas[i]);
        }

		quicksort_descending_order(notas, 0, n - 1);

		while (q--)
		{
			scanf("%d", &rank);
			printf("%d\n", notas[rank - 1]);
		}
	}

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