/*
Calculating area and volume of a sphere using pointers.
*/

#include <stdio.h>
#include <math.h>

float calc_esfera(float, float *, float *);

int main(void)
{
    float r, area, vol;
    printf("Enter radius: ");
    scanf("\n%f", &r);
    calc_esfera(r, &area, &vol);
    printf("Area: %.2f\nVolume: %.2f\n", area, vol);

    return 0;
}

float calc_esfera(float r, float *area, float *volume)
{
    *area = 4 * 3.14 * pow(r, 2);
    *volume = 4 * 3.14 * pow(r, 3) / 3;
}