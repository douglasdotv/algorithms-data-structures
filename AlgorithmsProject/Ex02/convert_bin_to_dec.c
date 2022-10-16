/*
Converting a binary number to a decimal number using pointers.
*/

#include <stdio.h>

void convert_bin_to_dec(int *);

int main()
{
    int bin_number;
    printf("Enter a binary number: ");
    scanf("\n%d", &bin_number);
    printf("The decimal equivalent of the binary number %d is ", bin_number);
    convert_bin_to_dec(&bin_number);
    printf("%d.\n", bin_number);
    return 0;
}

void convert_bin_to_dec(int *num)
{
    int x = 0, base = 1, remainder;
    while (*num > 0)
    {
        remainder = *num % 10;
        x += remainder * base;
        *num /= 10;
        base *= 2;
    }
    *num = x;
}