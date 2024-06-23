#include <stdio.h>
int main()
{
    int arr[20] = {10,22,95,78,45};
    int i, x, pos, n = 5;
    printf("\nArray elements before insertion : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    x = 100;
    pos = 3;
    n++;

    for (i = n - 1; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = x;

    printf("\nThe item %d is added at %dth position : ", x, pos);
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}