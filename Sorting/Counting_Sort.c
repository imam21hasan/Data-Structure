#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n)
{
    int i, maxElement = 0;

    for (i = 0; i < n; i++)
    {
        if (arr[i] > maxElement)
        {
            maxElement = arr[i];
        }
    }

    int *count = (int *)calloc(maxElement + 1, sizeof(int));
    int *temp = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (i = 1; i <= maxElement; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        temp[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }

    free(count);
    free(temp);
}

int main()
{
    int arr[] = {9,1,5,1,2,7,5,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The main array is : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    countingSort(arr, n);

    printf("\nThe sorted array is : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}