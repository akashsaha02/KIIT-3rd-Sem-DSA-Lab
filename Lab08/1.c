#include <stdio.h>
int main()
{
    int ar[20];
    printf("enter elements:");
    scanf("%d%d%d%d%d%d%d%d%d%d%d", &ar[0], &ar[1], &ar[2], &ar[3], &ar[4], &ar[5], &ar[6], &ar[9], &ar[13], &ar[14], &ar[15]);
    printf("The tree in array representation is:");
    printf("%d%d%d%d%d%d%d%d%d%d%d", ar[0], ar[1], ar[2], ar[3], ar[4], ar[5], ar[6], ar[9], ar[13], ar[14], ar[15]);
    return 0;
}