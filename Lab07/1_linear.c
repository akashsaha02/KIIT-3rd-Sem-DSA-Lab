#include <stdio.h>
int lsearch(int arr[], int N, int x)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    int n, key;
    printf("Enter number of elements: \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: \n");
    scanf("%d", &key);
    int N = sizeof(arr) / sizeof(arr[0]);
    int result = lsearch(arr, N, key);
    (result == -1)
        ? printf("Element is not present in array")
        : printf("Element is present at index %d", result);
    return 0;
}