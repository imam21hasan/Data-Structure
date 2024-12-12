#include <stdio.h>
int main()
{
    int n, i, j, min, temp;
    int arr[] = {20, 10, 30, 50, 40};
    n = sizeof(arr) / sizeof(arr[0]);

    printf("\nThe main array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    printf("\nAfter the selection sort : ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}