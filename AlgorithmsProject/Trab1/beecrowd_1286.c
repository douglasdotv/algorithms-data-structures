/*
Beecrowd 1286 – Motoboy – https://www.beecrowd.com.br/judge/en/problems/view/1286
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define LMAX 21
#define CMAX 31
#define MAXVALUE(a, b) a > b ? a : b

typedef struct
{
    int tempo;
    int pizzas;
} TPedido;

int main()
{
    TPedido pedido[LMAX];

    int md_array[LMAX][CMAX], n, p, i, j;

    while (scanf("%d", &n) && n)
    {
        scanf("%d", &p);
        for (i = 1; i <= n; i++)
        {
            scanf("%d %d", &pedido[i].tempo, &pedido[i].pizzas);
        }

        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= p; j++)
            {
                if (!i || !j)
                {
                    md_array[i][j] = 0;
                }
                else if (pedido[i].pizzas > j)
                {
                    md_array[i][j] = md_array[i - 1][j];
                }
                else
                {
                    md_array[i][j] = MAXVALUE(md_array[i - 1][j - pedido[i].pizzas] + pedido[i].tempo, md_array[i - 1][j]);
                }
            }
        }

        printf("%d min.\n", md_array[n][p]);
    }

    return 0;
}