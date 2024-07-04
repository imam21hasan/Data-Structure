#include <stdio.h>
int main()
{
    int arr[20] = {10, 20, 30, 40, 50};
    int i, item;
    int n =5;

    printf("The main array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    printf("\nEnter your inserted item : ");
    scanf("%d", &item);

    n++;
    arr[n-1] = item;

    printf("The array after %d insert at last position : ",item);
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}