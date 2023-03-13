/*
Verifying if a matrix (multidimensional array) is an upper triangular matrix.
*/

#include <stdio.h>
#include <stdbool.h>

void print_md_array(int, int, int a[][69]);
bool upper_triangular_matrix(int, int[][69]);

int main(void)
{
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int b[3][3] = {
        {1, 1, 1},
        {0, 1, 1},
        {0, 0, 1}};

    printf("a: \n");
    print_md_array(3, 3, a);
    printf("b: \n");
    print_md_array(3, 3, b);

    printf("Is 'a' an upper triangular matrix?\n");
    upper_triangular_matrix(3, a) ? printf("Yes.\n") : printf("No.\n");
    printf("Is 'b' an upper triangular matrix?\n");
    upper_triangular_matrix(3, b) ? printf("Yes.\n") : printf("No.\n");

    return 0;
}

bool upper_triangular_matrix(int order, int array[][order])
{
    bool above = true, below = true;

    for (int i = 0; i < order; i++)
    {
        for (int j = i; j < order; j++)
        {
            if (array[i][j] == 0)
            {
                above = false;
            }
        }
    }

    for (int i = 1; i < order; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[i][j] != 0)
            {
                below = false;
            }
        }
    }

    return above && below;
}

void print_md_array(int n, int m, int a[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        putchar('\n');
    }
}