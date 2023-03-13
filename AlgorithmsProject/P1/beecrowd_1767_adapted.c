/*
Beecrowd 1767 – Santa Claus Bag – https://www.beecrowd.com.br/judge/pt/problems/view/2534
(Knapsack problem)
(Adapted: no running time restrictions and no need to print the amount of packets left.)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void imprime_qtd_brinquedos_e_peso(int[], int[], int, int);

int main(void)
{
    int k = 0, n, pac, c = 50;
    scanf("%d", &n);

    do
    {
        scanf("%d", &pac);
        int qt[pac], p[pac];
        for (int i = 0; i < pac; i++)
        {
            scanf("%d %d", &(qt[i]), &(p[i]));
        }
        imprime_qtd_brinquedos_e_peso(p, qt, c, pac);
        k++;
    } while (k < n);

    return 0;
}

void imprime_qtd_brinquedos_e_peso(int p[], int v[], int c, int n)
{
    int pos, valor, peso, max = 0, m = (int)pow(2, n), pesomax;
    for (int i = 0; i < m; i++)
    {
        valor = peso = 0;
        for (int j = 0; j < n; j++)
        {
            pos = (i >> j) % 2;
            if (pos == 1)
            {
                valor += v[j];
                peso += p[j];
            }
        }
        if (peso <= c && valor > max)
        {
            max = valor;
            pesomax = peso;
        }
    }
    printf("%d brinquedos\n", max);
    printf("Peso: %d kg", pesomax);
    puts("\n");
}
