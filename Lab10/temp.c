// MAX heap dsa
#include <stdio.h>
int size = 0;
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void heapify(int arr[], int size, int i)
{
    if (size == 1)
    {
        printf("Single element in the heap");
    }
    else
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && arr[l] > arr[largest])
        {
            largest = l;
        }
        if (l < size && arr[r] > arr[largest])
        {
            largest = r;
        }
        if (largest != i)
        {
            swap(&arr[i], &arr[largest]);
            heapify(arr, size, largest);
        }
    }
}

void insert(int arr[], int newnum)
{
    if (size == 0)
    {
        arr[0] = newnum;
        size += 1;
    }
    else
    {
        arr[size] = newnum;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i++)
        {
            heapify(arr, size, i);
        }
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    int array[10];

    insert(array, 3);
    insert(array, 4);
    insert(array, 9);
    insert(array, 5);
    insert(array, 2);

    printf("Max-Heap array: ");
    printArray(array, size);
    
    return 0;
}