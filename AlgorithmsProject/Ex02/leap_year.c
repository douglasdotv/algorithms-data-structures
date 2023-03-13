/*
Verifying if a given year is a leap year.
*/

#include <stdio.h>
#include <stdbool.h>

bool verify_leap_year(int);

int main(void)
{
    int year;
    printf("Enter a year: ");
    scanf("\n%llu", &year);

    if (verify_leap_year(year))
    {
        printf("%d is a leap year.", year);
    }
    else
    {
        printf("%d isn't a leap year.", year);
    }

    return 0;
}

bool verify_leap_year(int year)
{
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    {
        return true;
    }
    return false;
}