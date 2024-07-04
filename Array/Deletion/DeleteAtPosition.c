#include <stdio.h>
int main()
{
    int arr[20] = {10, 20, 30, 40, 50};
    int i, pos;
    int n = 5;

    printf("The main array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    printf("\nEnter the position : ");
    scanf("%d", &pos);

    for (i = pos - 1; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;

    printf("The array after deleted %dth element : ", pos);
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}