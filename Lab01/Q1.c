#include <stdio.h>
int main()
{
    int i, max, min, n;
    float sum = 0;
    printf("Enter size:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    max = arr[0];
    min = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        sum += arr[i];
    }
    printf("Maximum element = %d\nMinimum element = %d\nSum = %d\nAverage = %f\n", max, min, min + max);
    return 0;
}