#include <stdio.h>
#include <stdlib.h>

void swap(int *p, int *q)
{
    int a = *p;
    *p = *q;
    *q = a;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftindex = 2 * i;
    int rightindex = 2 * i + 1;
    if (leftindex <= n && arr[leftindex] >= arr[largest])
        largest = leftindex;
    if (rightindex <= n && arr[rightindex] >= arr[largest])
        largest = rightindex;
    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        heapify(arr, n, largest);
    }
    return;
}

void heap_sort(int arr[], int size) // TC:- O(nlogn);
{
    int n = size;
    while (n > 1)
    {
        swap(&arr[1], &arr[n]);
        n--;
        heapify(arr, n, 1);
    }
}

int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    printf("Array before sorting:- \n");
    for (int i = 1; i < 6; i++)
        printf("%d ", arr[i]);
    for (int i = n / 2; i >= 1; i--)
        heapify(arr, n, i);
    heap_sort(arr, n);
    printf("\n");
    printf("Array after sorting:- \n");
    for (int i = 1; i < 6; i++)
        printf("%d ", arr[i]);
    return 0;
}