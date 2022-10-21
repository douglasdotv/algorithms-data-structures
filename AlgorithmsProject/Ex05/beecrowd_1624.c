/*
Beecrowd 1624 – Promotion – https://www.beecrowd.com.br/judge/pt/problems/view/2534
(Knapsack problem)
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int supermarket_recursive(int[], int[], int, int, int);

int main()
{
    do
    {
        int n, c;
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        int v[n], w[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &v[i], &w[i]);
        }
        scanf("%d", &c);
        printf("%d\n", supermarket_recursive(w, v, c, n, 0));
    } while (true);

    return 0;
}

int supermarket_recursive(int w[], int v[], int c, int n, int item)
{
    if (c == 0 || item >= n)
    {
        return 0;
    }
    if (w[item] > c)
    {
        return supermarket_recursive(w, v, c, n, item + 1);
    }   
    int r_max = v[item] + supermarket_recursive(w, v, c - w[item], n, item + 1);
    int l_max = supermarket_recursive(w, v, c, n, item + 1);
    return (r_max > l_max ? r_max : l_max);
}