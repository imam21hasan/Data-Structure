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
    for (i = n-1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = item;

    printf("The array after %d insert at 1st position : ",item);
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}
