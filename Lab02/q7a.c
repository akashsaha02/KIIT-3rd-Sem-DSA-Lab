#include <stdio.h>
#include <math.h>
struct co_ord
{
    int xco;
    int yco;
};
int main()
{
    float d;
    struct co_ord p1;
    struct co_ord p2;
    printf("Enter x1");
    scanf("%d", &p1.xco);
    printf("Enter y1");
    scanf("%d", &p1.yco);

    printf("Enter x2");
    scanf("%d", &p2.xco);
    printf("Enter y2");
    scanf("%d", &p2.yco);
    d = sqrt(((p2.xco - p1.xco) * (p2.xco - p1.xco)) + ((p2.yco - p1.yco) * (p2.yco - p1.yco)));
    printf("Distance: %f", d);
    return 0;
}