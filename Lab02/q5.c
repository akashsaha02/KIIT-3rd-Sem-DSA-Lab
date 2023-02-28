#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr1;
    int *ptr2;
    int n, count, i, j;

    printf("Enter array size: ");
    scanf("%d", &n);

    ptr1 = (int *)malloc(n * sizeof(int));
    ptr2 = (int *)malloc(n * sizeof(int));

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr1[i]);
    }
    for (i = 0; i < n; i++)
    {
        count = 0;
        for (j = i + 1; j < n; j++)
        {
            if (ptr1[i] < ptr1[j])
            {
                ptr2[i] = ptr1[j];
                count = 1;
                break;
            }
        }
        if (count == 0)
        {
            ptr2[i] = -1;
        }
    }
    printf("The NGE are\n");
    for (i = 0; i < n; i++)
    {
        printf("%d \t", ptr2[i]);
    }
    free(ptr1);
    free(ptr2);
    return 0;
}