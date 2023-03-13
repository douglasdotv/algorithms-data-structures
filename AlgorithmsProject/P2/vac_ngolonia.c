/*
O Ministério da Saúde da Nlogônia está planejando a vacinação em massa da sua população,
para isso você deve escrever um programa em C que dadas algumas informações de todos os cidadãos
da Nlogônia informe a ordem de vacinação da população.

Os critérios de vacinação do Ministério da Saúde da Nlogônia são os seguintes:
Serão vacinados primeiros os mais velhos;
Em caso de empate na idade, serão vacinado primeiro os com doença crônica;
Persistindo o empate, serão vacinados primeiro de menor número de registro, que é único para cada habitante.

Como o Ministério da Saúde da Nlogônia tem pressa, seu programa deve dar uma resposta rápida,
portanto, deve ser empregado um algoritmo eficiente de ordenação.

Entrada:
A primeira linha da entrada consiste em um inteiro N (1 ≤ N ≤ 108), o número de habitantes da Nlogônia.
As N linhas seguintes descrevem cada um dos habitantes da Nlogônia e contém 3 inteiros, I (0 ≤ I ≤ 120),
D (D = 1 se tem doença crônica ou D = 0, caso contrário) e R (1 ≤ R ≤ N),
representando a idade, se tem doença crônica ou não e o número de registro de cada habitante, respectivamente.

Saída:
Seu programa deve produzir N linhas na saída, contendo o 
número de registro dos habitantes na ordem em que eles serão vacinados.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int i;
    int d;
    int r;
} Habitante;

int compare(const void *, const void *);

int main(void)
{
    int n;
    scanf("%d", &n);

    Habitante habitantes[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d %d", &habitantes[i].i, &habitantes[i].d, &habitantes[i].r);
    }

    qsort(habitantes, n, sizeof(Habitante), compare);

    for (int i = 0; i < n; ++i)
    {
        printf("%d\n", habitantes[i].r);
    }

    return 0;
}

int compare(const void *a, const void *b)
{
    const Habitante *habitante_A = a;
    const Habitante *habitante_B = b;

    if (habitante_A->i == habitante_B->i)
    {
        if (habitante_A->d == habitante_B->d)
        {
            if (habitante_A->r == habitante_B->r)
            {
                return 0;
            }

            return habitante_A->r - habitante_B->r;
        }

        return habitante_B->d - habitante_A->d;
    }

    return habitante_B->i - habitante_A->i;
}
