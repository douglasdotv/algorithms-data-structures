/*
Printing the next day date for each inputted date.
*/

#include <stdio.h>
#include <stdbool.h>

void get_next_day(int *, int *, int *);
bool verify_leap_year(int);

int main(void)
{
    int n;
    printf("Enter n (amount of dates): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nDate %d\n", i + 1);
        int day, month, year;
        printf("Enter day, month and year: \n");
        scanf("%d %d %d", &day, &month, &year);

        printf("Current date: \n");
        printf("%d/%d/%d\n", day, month, year);

        get_next_day(&day, &month, &year);

        printf("Next day date: \n");
        printf("%d/%d/%d\n", day, month, year);
    }

    return 0;
}

void get_next_day(int *day, int *month, int *year)
{
    if (*day > 31 || *month > 12)
    {
        printf("Invalid input!");
    }
    else
    {
        (*day)++;
        if ((*month == 1 || *month == 3 || *month == 5 || *month == 7 || *month == 8 || *month == 10 || *month == 12) && *day > 31)
        {
            *day = 1;
            (*month)++;
        }
        else if ((*month == 4 || *month == 6 || *month == 9 || *month == 11) && *day > 30)
        {
            *day = 1;
            (*month)++;
        }
        else if (month == 2)
        {
            if (verify_leap_year(year))
            {
                if (*day > 29)
                {
                    *day = 1;
                    (*month)++;
                }
            }
            else
            {
                if (*day > 28)
                {
                    *day = 1;
                    (*month)++;
                }
            }
        }
        if (*month == 13)
        {
            *month = 1;
            (*year)++;
        }
    }
}

bool verify_leap_year(int year)
{
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    {
        return true;
    }
    return false;
}