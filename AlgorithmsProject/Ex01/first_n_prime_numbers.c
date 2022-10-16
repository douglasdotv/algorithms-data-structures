/*
Printing the first n prime numbers.
*/

#include <stdio.h>
#include <stdbool.h>

bool prime(int);

int main()
{
    int n, counter = 0, i = 2;
    printf("Enter a number (or enter 0 to exit the program): ");
    scanf("\n%d", &n);

    printf("Printing the first %d prime numbers: \n", n);
    do
    {
        if (prime(i))
        {
            printf("%d ", i);
            counter++;
        }
        i++;
    } while (counter < n);
    
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