#include <stdio.h>
int main()
{
    int arr[5] = {11, 22, 33, 44, 55};
    int item = 50, i, pos = 3;

    printf("\nThe main array is : ");
    for (i = 0; i < 5; i++)
    {
        printf("%d  ", arr[i]);
    }

    arr[pos - 1] = item;

    printf("\nThe array after update : ");
    for (i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d  ", i, arr[i]);
    }

    return 0;
}