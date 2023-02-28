#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr;
    int n, a1, a2, count;
    printf("Enter array size: ");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    printf("Enter elements:\n ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }
    printf("Enter the 1st element: ");
    scanf("%d", &a1);
    printf("Enter the 2nd element: ");
    scanf("%d", &a2);
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (ptr[i] >= a1 && ptr[i] <= a2)
        {
            printf("%d,", ptr[i]);
            count++;
        }
    }
    printf("\nNo of elements found is :%d", count);
    free(ptr);
    return 0;
}