/*
Recursively converting a decimal number to a binary number.
*/

#include <stdio.h>

void convert_dec_to_bin_rec(int);

int main(void)
{
    int number;
    printf("Enter a decimal number: ");
    scanf("%d", &number);

    printf("Converting %d to a binary number: \n", number);
    convert_dec_to_bin_rec(number);

    puts(" ");

    return 0;
}

void convert_dec_to_bin_rec(int n)
{
    if (n < 2)
    {
        printf("%d", n);
    }
    else
    {
        convert_dec_to_bin_rec(n / 2);
        printf("%d", n % 2);
    }
}