#include <stdio.h>

void merge(int arr[], int b, int m, int e)
{
    int i, j, k;
    int n1 = m - b + 1;
    int n2 = e - m;

    int leftArray[n1], rightArray[n2];

    for (i = 0; i < n1; i++)
        leftArray[i] = arr[b + i];
    for (j = 0; j < n2; j++)
        rightArray[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = b;
    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int beg, int end)
{
    if (beg < end)
    {

        int mid = (beg + end) / 2;

        mergeSort(arr, beg, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, beg, mid, end);
    }
}
void printArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int arr[] = {77, 4, 61, 25, 37, 50, 88};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nThe main array is : ");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("\nAfter the merge sort : ");
    printArray(arr, n);

    return 0;
}