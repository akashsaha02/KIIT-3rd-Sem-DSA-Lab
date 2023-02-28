#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter no of num: ");
    scanf("%d", &n);
    int *no = (int *)malloc(n * sizeof(int));
    printf("\nEnter the no: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &no[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (no[i] % 2 == 0)
        {
            printf("%d,", no[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (no[i] % 2 != 0)
        {
            printf("%d,", no[i]);
        }
    }
    return 0;
}