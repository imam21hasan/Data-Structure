#include <stdio.h>
int main()
{
    int i, n, sum = 0;
    printf("\nEnter the array size : ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter array element : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("The array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    for (i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    printf("\nArray sum is : %d", sum);
    printf("\nAvarage is : %.2f", (float)sum / n);

    int arr2[n];
    for (i = 0; i < n; i++)
    {
        arr2[i] = arr[i];
    }
    printf("\nThe copy array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr2[i]);
    }

    return 0;
}
