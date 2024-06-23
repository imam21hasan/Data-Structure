#include <stdio.h>
int main()
{
    int arr[] = {11, 22, 33, 44, 55};
    int i, j, k = 22, n = 5;

    printf("\nThe main array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    j = k;

    while (j < n)
    {
        arr[j - 1] = arr[j];
        j = j + 1;
    }

    n = n - 1;

    printf("\nThe array after deletion : ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}