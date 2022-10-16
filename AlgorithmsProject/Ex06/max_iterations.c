/*
Finding the maximum number of operations that a binary search algorithm will perform in a n-element array.
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter total amount of elements: ");
    scanf("%d", &n);

    int i = (int)(log(n) / log(2)) + 1; // log2(n) = ln(n)/ln(2)
    printf("If we have %d elements, then max iterations = %d.", n, i);

    return 0;
}