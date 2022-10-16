/*
Counting how many times a digit 'd' appears on a given number 'n'.
Also, function is_permutation reads two numbers 'a' and 'b' and returns true if a is permutation of b and false otherwise.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int count_digits(int, int);
bool is_permutation(int, int);

int main()
{
    int x = 5412434, y = 4321445, z = 4312455, digit;

    printf("Enter a digit: ");
    scanf("\n%d", &digit);

    if (count_digits(x, digit) == 1)
    {
        printf("Digit %d appears once on number %d.\n", digit, x);
    }
    else
    {
        printf("Digit %d appears %d times on number %d.\n", digit, count_digits(x, digit), x);
    }

    is_permutation(x, y) ? printf("%d is a permutation of %d.\n", x, y) : printf("%d isn't a permutation of %d.\n", x, y);
    is_permutation(x, z) ? printf("%d is a permutation of %d.\n", x, z) : printf("%d isn't a permutation of %d.\n", x, z);

    return 0;
}

int count_digits(int n, int d)
{
    char number[255];
    sprintf(number, "%d", n);

    int counter = 0;
    for (int i = 0; i < strlen(number); i++)
    {
        if (d == number[i] - 48) // (ASCII)
            counter++;
    }

    return counter;
}

bool is_permutation(int a, int b)
{
    int counter = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (count_digits(a, i) == count_digits(b, i))
            counter++;
    }
    if (counter == 9)
    {
        return true;
    }
    else
    {
        return false;
    }
}