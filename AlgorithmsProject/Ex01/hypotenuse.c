/*
Calculating the hypotenuse 'a' of a triangle with sides a, b and c.
*/

#include <stdio.h>

double hypotenuse(double, double);

int main(void)
{
    double b, c;
    printf("Enter b: ");
    scanf("\n%lf", &b);
    printf("Enter c: ");
    scanf("\n%lf", &c);
    printf("a^2 = %.0lf^2 + %.0lf^2 =>\na = sqrt(%.0lf^2 + %.0lf^2)=>\na = sqrt(%.0lf) =>\na = %.2lf",
           b, c, b, c, pow(b, 2) + pow(c, 2), hypotenuse(b, c));

    return 0;
}

double hypotenuse(double x, double y)
{
    return sqrt(x * x + y * y);
}