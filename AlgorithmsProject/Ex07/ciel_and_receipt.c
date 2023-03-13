/*
Ciel and Receipt — https://www.codechef.com/problems/CIELRCPT
*/

#include <stdio.h>

int main(void)
{
    int t, p, min_menus, pow;
    scanf("%d", &t);

    while (t > 0)
    {
        scanf("%d", &p);

        min_menus = 0, pow = 2048;

        while (p != 0)
        {
            if (p / pow > 0)
            {
                min_menus += p / pow;
                p %= pow;
            }
            pow /= 2;
        }

        printf("%d\n", min_menus);

        t--;
    }

    return 0;
}
