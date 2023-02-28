#include <stdio.h>
struct distance
{
    int km;
    int m;
};
void addDistance(struct distance d1, struct distance d2)
{
    struct distance d3;
    d3.km = d1.km + d2.km;
    d3.m = d1.m + d2.m;

    d3.km = d3.km + d3.m / 1000;
    d3.m = d3.m % 1000;

    printf("\nTotal distance- Kilometer: %d, Meter: %d", d3.km, d3.m);
}

int main()
{
    struct distance d1, d2;

    printf("Enter first distance in kilometer and meter:");
    scanf("%d%d", &d1.km, &d1.m);

    printf("Enter second distance in kilometer and meter:");
    scanf("%d%d", &d2.km, &d2.m);
    
    addDistance(d1, d2);
    return 0;
}