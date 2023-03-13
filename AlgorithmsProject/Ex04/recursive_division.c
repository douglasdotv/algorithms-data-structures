/*
Recursively dividing two numbers.
*/

#include <stdio.h>

int recursive_division(int, int);

int main(void)
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("\n%d %d", &a, &b);
    
    printf("%d divided by %d is %d (remainder: %d)", a, b, recursive_division(a, b), a - b * recursive_division(a, b));

    return 0;
}

int recursive_division(int a, int b)
{
    if (a < b)
    {
        return 0;
    }

    return (1 + recursive_division(a - b, b));
}