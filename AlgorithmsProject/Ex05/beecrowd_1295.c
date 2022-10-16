/*
Beecrowd 1295 – The Closest Pair Problem – https://www.beecrowd.com.br/judge/en/problems/view/1295
(No time limit restrictions)
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define INT_MAX (2147483647)

typedef struct
{
    int x;
    int y;
} Point;

typedef struct
{
    Point p1;
    Point p2;
} PairOfPoints;

PairOfPoints get_closest_pair(int, Point[]);

int main()
{
    while (true)
    {
        int n;
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }

        Point points[n];

        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &(points[i].x), &(points[i].y));
        }

        PairOfPoints closest_pair = get_closest_pair(n, points);
        double dist_closest_pair = sqrt(pow(closest_pair.p1.x - closest_pair.p2.x, 2) + pow(closest_pair.p1.y - closest_pair.p2.y, 2));

        if (dist_closest_pair < 10000)
        {
            printf("%.4f\n", dist_closest_pair);
        }
        else
        {
            printf("INFINITY\n");
        }
    }
    return 0;
}

PairOfPoints get_closest_pair(int n, Point p[])
{
    double min_dist = INT_MAX, dist;
    PairOfPoints closest;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            dist = sqrt(pow(p[i].x - p[j].x, 2) + pow(p[i].y - p[j].y, 2));
            if (dist < min_dist)
            {
                min_dist = dist;
                closest = (PairOfPoints){p[i], p[j]};
            }
        }
    }
    return closest;
}