/*
Multiplying two matrices of dimensions (n,m) and (m,k) and printing the resulting matrix.
*/

#include <stdio.h>

void mult_mat(int, int, int, int[][69], int[][69], int[][69]);
void get_md_array_elements(int, int, int[][69]);
void print_md_array(int, int, int[][69]);

int main()
{
    int n, m, k;
    printf("Enter n, m and k: \n");
    scanf("%d %d %d", &n, &m, &k);

    int a[n][m], b[m][k], c[n][k];

    printf("\nEnter the first matrix elements.\n");
    get_md_array_elements(n, m, a);
    printf("\nEnter the second matrix elements.\n");
    get_md_array_elements(m, k, b);

    printf("\nMatrix a[][]: \n");
    print_md_array(n, m, a);
    printf("\nMatrix b[][]: \n");
    print_md_array(m, k, b);

    printf("\nMultiplying a and b...\n");
    mult_mat(n, m, k, a, b, c);

    printf("\nResulting matrix c[][]: \n");
    print_md_array(n, k, c);

    return 0;
}

void mult_mat(int n, int m, int k, int a[][m], int b[][k], int c[][k])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            c[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            for (int k = 0; k < m; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void get_md_array_elements(int r, int c, int a[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
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