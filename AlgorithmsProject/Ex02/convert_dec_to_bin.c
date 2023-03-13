/*
Converting a decimal number to a binary number using pointers.
*/

#include <stdio.h>
#include <math.h>

void convert_dec_to_bin(int *);
int get_floor_power(int);

int main(void)
{
    int decimal_number;
    printf("Enter a decimal number: ");
    scanf("\n%d", &decimal_number);
    printf("Converting %d to a binary number: ", decimal_number);
    convert_dec_to_bin(&decimal_number);
    printf("%d\n", decimal_number);

    return 0;
}

void convert_dec_to_bin(int *num)
{
    int x = *num, string_bin_index = 0;
    char string_bin[69];
    for (int i = get_floor_power(*num); i >= 0; i--)
    {
        if (x >= pow(2, i))
        {
            x -= pow(2, i);
            string_bin[string_bin_index] = '1';
        }
        else
        {
            string_bin[string_bin_index] = '0';
        }
        string_bin_index++;
    }
    *num = atoll(string_bin);
}

int get_floor_power(int n)
{
    int counter = 0;
    while (n > 1)
    {
        n /= 2;
        counter++;
    }
    return counter;
}