#include <stdio.h>
int main()
{
    int arr[20] = {10, 20, 30, 40, 50};
    int i;
    int n = 5;

    printf("The main array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    for (i=0;i<n-1;i++)
    {
        arr[i] = arr[i+1];
    }
    n--;

    printf("\nThe array after deleted 1st element : ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}
