/*
Checking if entered numbers are prime.
*/

#include <stdio.h>
#include <stdbool.h>

bool prime(int);

int main(void)
{
    int n;
    while (n != 0)
    {
        printf("Enter a number (or enter 0 to exit the program): ");
        scanf("\n%d", &n);
        if (n < 0)
        {
            printf("Invalid input (n < 0)\n");
        }
        else if (n == 0)
        {
            break;
        }
        else
        {
            if (prime(n))
            {
                printf("%d is prime\n", n);
            }
            else
            {
                printf("%d isn't prime\n", n);
            }
        }
    }
    
    return 0;
}

bool prime(int m)
{
    if (m == 0 || m == 1)
    {
        return false;
    }
    else
    {
        int counter = 0;
        for (int i = 1; i <= m; i++)
        {
            if (m % i == 0)
            {
                counter++;
            }
        }
        if (counter > 2)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}