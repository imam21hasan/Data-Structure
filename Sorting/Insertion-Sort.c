#include <stdio.h>
int main()
{
    int arr[] = {30, 20, 10, 40};
    int n, i, j, temp;

    n = sizeof(arr) / sizeof(arr[0]);

    printf("\nThe main array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    printf("\nAfter the insetion sort : ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}
