/*
Multiplying a matrix (multidimensional array) by a scalar.
*/

#include <stdio.h>

void scalar_multiplication(int, int, double a[][69], double);
void get_md_array_elements(int, int, double[][69]);
void print_md_array(int, int, double a[][69]);

int main()
{
    int r, c;
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    double a[r][c];
    get_md_array_elements(r, c, a);

    double scalar;
    printf("\nEnter a real number: \n");
    scanf("%lf", &scalar);

    printf("\nThis is our matrix: \n");
    print_md_array(r, c, a);

    printf("\nMultiplying it by scalar %.lf, we get: \n", scalar);
    scalar_multiplication(r, c, a, scalar);
    print_md_array(r, c, a);
    puts("");

    return 0;
}

void scalar_multiplication(int n, int m, double a[n][m], double number)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] *= number;
        }
    }
}

void get_md_array_elements(int r, int c, double a[r][c])
{
    printf("\nEnter matrix elements.\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter a%d%d: ", i + 1, j + 1);
            scanf("%lf", &a[i][j]);
        }
    }
}

void print_md_array(int n, int m, double a[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%.1lf ", a[i][j]);
        }
        putchar('\n');
    }
}