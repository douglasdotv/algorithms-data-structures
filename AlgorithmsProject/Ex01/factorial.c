/*
Calculating the factorial of a number.
*/

#include <stdio.h>

void factorial(int);

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("\n%d", &n);
    factorial(n);
    return 0;
}

void factorial(int n)
{
    long long sum = 1;
    if (n > 1)
    {
        for (int i = 2; i <= n; i++)
        {
            sum *= i;
        }
    }
    printf("%d! = %lld", n, sum);
}