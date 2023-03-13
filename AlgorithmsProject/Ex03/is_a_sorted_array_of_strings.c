/*
Checking if an array of strings is in alphabetical order.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_a_sorted_array_of_strings(int, char[][21]);

int main(void)
{
    int n;
    printf("Enter n (total amount of strings): ");
    scanf("%d", &n);

    char strings[n][21];
    for (int i = 0; i < n; i++)
    {
        printf("Enter a string: ", n);
        scanf("%s", &strings[i]);
    }
    
    is_a_sorted_array_of_strings(n, strings) ? printf("Alphabetical order: YES") : printf("Alphabetical order: NO");

    return 0;
}

bool is_a_sorted_array_of_strings(int n, char array[][21])
{
    for (int i = 0; i < n - 1; i++)
    {
        if(strcmp(array[i + 1], array[i]) < 0)
        {
            return false;
        }
    }
    return true;
}