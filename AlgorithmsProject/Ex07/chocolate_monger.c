/*
Chocolate Monger — https://www.codechef.com/problems/CM164364
*/

#include <stdio.h>

int cmpfunc(const void *, const void *);

int main(void)
{
    int t, n, x, total_flavours, last_type, eat, chocolates[200000];

    scanf("%d", &t);

    while (t > 0)
    {
        scanf("%d %d", &n, &x);

        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &chocolates[i]);
        }

        qsort(chocolates, n, sizeof(int), cmpfunc);

        eat = n - x, total_flavours = 0, last_type = -1;

        for (int i = 0; i < n && eat > 0; ++i)
        {
            if (chocolates[i] != last_type)
            {
                last_type = chocolates[i];
                total_flavours++;
                eat--;
            }
        }

        printf("%d\n", total_flavours);

        t--;
    }

    return 0;
}

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
