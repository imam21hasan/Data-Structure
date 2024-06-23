#include <stdio.h>
int main()
{
    int i, arr[5];

    printf("Enter the array element : ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    for (i = 1; i < 5; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    printf("The maximum number is : %d \n", max);

    int min=arr[0];
    for (i = 1; i < 5; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    printf("The maximum number is : %d \n", min);

    return 0;
}