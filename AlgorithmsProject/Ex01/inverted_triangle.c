/* 
Drawing an inverted triangle formed by 'n' characters 'ch' in its base.
*/

#include <stdio.h>
#include <stdlib.h>

void inverted_triangle(int, char);

int main(void)
{
    int n;
    char ch;

    printf("Enter n > 2: ");
    scanf("\n%d", &n);
    if (n <= 2)
    {
        printf("Invalid input (n <= 2). Enter n > 2 next time.");
        exit(0);
    }

    printf("Enter ch: ");
    scanf("\n%c", &ch);

    printf("\nDrawing an inverted triangle with %d characters '%c' in its base: \n\n", n, ch);
    inverted_triangle(n, ch);

    return 0;
}

void inverted_triangle(int n, char c)
{
    int space = 1;
    for (int i = n; i > 0; i -= 2)
    {
        for (int j = 1; j <= space; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
        {
            printf("%c", c);
        }
        printf("\n");
        space++;
    }
}