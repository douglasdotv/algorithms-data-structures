/*
Recursively printing an array, from the first element to the last one.
*/

#include <stdio.h>

void imprimir_array_recursivamente(int[], int);
void inserir_elementos(int[], int);

int main(void)
{
    int n;
    printf("Digite a quantidade n de elementos presentes no array: \n");
    scanf("%d", &n);

    int array[n];
    inserir_elementos(array, n);

    printf("Imprimindo os elementos do array, do primeiro ao último, recursivamente: \n");
    imprimir_array_recursivamente(array, n);
}

void imprimir_array_recursivamente(int a[], int n)
{
    if (n == 1)
    {
        printf("%d ", a[0]);
        return;
    }
    imprimir_array_recursivamente(a, n - 1);
    printf("%d ", a[n - 1]);
}

void inserir_elementos(int a[], int n)
{
    printf("Insira os %d elementos do array: \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
