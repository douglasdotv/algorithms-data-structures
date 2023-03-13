/*
Chef and Loss — https://www.codechef.com/problems/CFLOS
(Fractional knapsack)
*/

#include <stdio.h>

typedef struct
{
    int index;
    int weight;
    int value;
} Item;

void fractional_knapsack(int, const Item[], int, double[]);
void quicksort(Item[], int, int);

int main(void)
{
    int t, n, c;
    Item itens[1000];
    double f[1000];

    scanf("%d", &t);

    while (t > 0)
    {
        scanf("%d %d", &n, &c);

        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &itens[i].weight);
        }

        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &itens[i].value);
        }

        for (int i = 0; i < n; ++i)
        {
            itens[i].index = i;
            f[i] = 0.0;
        }

        fractional_knapsack(n, itens, c, f);

        double loss = 0;
        for (int i = 0; i < n; ++i)
        {
            loss += f[i] * itens[i].value;
        }

        printf("%.0lf\n", loss);

        t--;
    }

    return 0;
}

void fractional_knapsack(int n, const Item itens[], int c, double f[])
{
    Item aux[n];

    for (int i = 0; i < n; ++i)
    {
        aux[i] = itens[i];
    }

    quicksort(aux, 0, n - 1);

    int i = 0;
    while (i < n && c >= aux[i].weight)
    {
        f[aux[i].index] = 1;
        c -= aux[i++].weight;
    }

    if (i < n)
    {
        f[aux[i].index] = (double)c / aux[i].weight;
    }
}

void quicksort(Item a[], int e, int d)
{
    int i = e, j = d;
    Item x = a[(i + j) / 2], aux;

    do
    {
        while ((double)a[i].value / a[i].weight > (double)x.value / x.weight)
        {
            i++;
        }
        while ((double)x.value / x.weight > (double)a[j].value / a[j].weight)
        {
            j--;
        }
        if (i <= j)
        {
            aux = a[i];
            a[i++] = a[j];
            a[j--] = aux;
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
