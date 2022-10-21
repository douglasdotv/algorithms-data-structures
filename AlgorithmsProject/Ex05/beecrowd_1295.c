/*
Beecrowd 1295 — The Closest Pair Problem (https://www.beecrowd.com.br/judge/en/problems/view/1295)
Algorithm explanation: https://www.youtube.com/watch?v=kCLGVat2SHk
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 9999.99999

typedef struct
{
    double x, y;
} Point;

double distance(Point q, Point r);
double closest(int a, int b);
int cmp(const void *a, const void *b);
double max(double a, double b) { return a > b ? a : b; }
double min(double a, double b) { return a < b ? a : b; }

Point p[10000];

int main()
{
    int n, i;
    double d;

    while (scanf("%d", &n) && n)
    {
        for (i = 0; i < n; i++)
            scanf("%lf %lf", &p[i].x, &p[i].y);

        qsort(p, n, sizeof(Point), cmp);

        d = closest(0, n - 1);
        if (d > MAX)
            printf("INFINITY\n");
        else
            printf("%.4lf\n", d);
    }

    return 0;
}

double distance(Point q, Point r)
{
    double d = sqrt((q.x - r.x) * (q.x - r.x) + (q.y - r.y) * (q.y - r.y));
    return min(d, MAX + 1.0);
}

double closest(int a, int b)
{
    int i, j;
    double dl, dr, d, xp;

    if (a == b)
        return MAX + 1.0;
    else if (b - a == 1)
        return distance(p[b], p[a]);
    else
    {
        dl = closest(a, (a + b) / 2);
        dr = closest((a + b) / 2 + 1, b);
        d = min(dl, dr);
        i = (a + b) / 2;
        xp = p[i].x;
        do
        {
            j = (a + b) / 2 + 1;
            while (xp - p[j].x < d && j <= b)
            {
                dl = distance(p[j], p[i]);
                d = min(d, dl);
                j++;
            }
            i--;
        } while (xp - p[i].x < d && i >= a);

        return d;
    }
}

int cmp(const void *a, const void *b)
{
    return ((Point *)a)->x - ((Point *)b)->x;
}