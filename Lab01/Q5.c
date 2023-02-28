#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int arr[] = {2, 4, 6, 8, 87, 7, 7, 76, 10, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *ptr = arr;
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", *(ptr + i));
    }
    int m;
    printf("Enter the size :");
    scanf("%d", &m);
    int array[m][m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d\t", (ptr + i * m + j));
        }
        printf("\n");
    }
    return 0;
}