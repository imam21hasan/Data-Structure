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

    n--;

    printf("\nThe array after deleted last element : ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}