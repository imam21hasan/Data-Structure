#include <stdio.h>
int main()
{
    int arr[20] = {10, 20, 30, 40, 50};
    int i, pos, item = 77;
    int n = 5;

    printf("The main array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    printf("\nEnter the position : ");
    scanf("%d", &pos);

    n++;
    for (i = n - 1; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = item;

    printf("The array after %d insert at position %d : ", item, pos);
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}