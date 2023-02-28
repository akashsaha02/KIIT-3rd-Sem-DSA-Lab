#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int n, i, ts, s;

    printf("Enter size: ");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    printf("Enter array elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &ts);
    s = 0;
    for (i = 0; i < n; i++)
    {
        if (ptr[i] == ts)
        {
            s = ts;
            break;
        }
    }
    if (s == ts)
    {
        printf("The element is found !\n");
    }
    else
    {
        printf("The element is not found");
    }
    free(ptr);
    return 0;
}