/*
Recursively calculating the value of the following the series:
1 + 1/2 + 1/3 + ... + 1/n
2/4 + 1 + 5/3 + ... + (n^2 + 1)/(n + 3)
*/

#include <stdio.h>
#include <math.h>

float series_1_n(int);
float series_n2plus1_nplus3(int);

int main(void)
{
    int n;
    printf("Enter n: \n");
    scanf("%d", &n);
    printf("The sum of the %d first terms of 1 + 1/2 + 1/3 + ... + 1/n is: \n%.2f\n", n, series_1_n(n));
    printf("The sum of the %d first terms of 2/4 + 1 + 5/3 + ... + (n^2 + 1)/(n + 3) is: \n%.2f\n", n, series_n2plus1_nplus3(n));

    return 0;
}

float series_1_n(int x)
{
    if (x == 0)
    {
        return 0;
    }
    return (1.0 / x + series_1_n(x - 1));
}

float series_n2plus1_nplus3(int x)
{
    if (x == 0)
    {
        return 0;
    }
    return (pow(x, 2.0) + 1) / (x + 3.0) + series_n2plus1_nplus3(x - 1);
}