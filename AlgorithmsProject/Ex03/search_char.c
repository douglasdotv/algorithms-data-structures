/*
Searching for the first occurence of a char on a string.
*/

#include <stdio.h>
#include <string.h>

int search_char(char[], char);

int main()
{
    char chosen_word[69], chosen_char;
    printf("Enter a word: ");
    scanf("%[^\n]", &chosen_word);
    printf("Now, enter a char to be searched: ");
    scanf("\n%c", &chosen_char);

    int index = search_char(chosen_word, chosen_char);
    if (index != -1)
    {
        printf("Char '%c' appears for the first time in string '%s' at index %d.\n", chosen_char, chosen_word, index);
    }
    else
    {
        printf("Char '%c' was not found in string '%s'.", chosen_char, chosen_word);
    }

    return 0;
}

int search_char(char string[], char specific_char)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == specific_char)
        {
            return i + 1;
        }
    }
    return -1;
}