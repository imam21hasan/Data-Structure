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

    int *count = (int *)calloc(maxElement + 1, sizeof(int));   // calloc memory value k "0" diye initialize kore.
    int *temp = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (i = 1; i <= maxElement; i++)   // comulative counts
    {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--)    // element sorted into temp
    {
        temp[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++)    // copy to main array
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