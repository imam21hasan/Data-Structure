#include <stdio.h>
int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int i = start, j = end;

    while (i < j)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else
        {
            int temp = arr[start];
            arr[start] = arr[j];
            arr[j] = temp;
        }
    }
    /*
    int temp = arr[start];
    arr[start] = arr[j];
    arr[j] = temp;
    */

    return j;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int p = partition(arr, start, end);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }
}

int main()
{
    int arr[] = {45, 8, 12, 64, 9, 3, 21, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The main array is : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("\nThe sorted array is : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}