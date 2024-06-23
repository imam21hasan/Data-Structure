#include <stdio.h>
int main()
{
    int arr[5] = {11, 22, 33, 44, 66};
    int item = 44, i, j = 0;

    printf("\nThe main array is : ");
    for (i = 0; i < 5; i++)
    {
        printf("%d  ", arr[i]);
    }

    printf("\nElement to be search %d", item);
    while (j < 5)
    {
        if (arr[j] == item)
        {
            break;
        }
        j++;
    }
    printf("\nElement %d is found at %d position", item, j + 1);

    return 0;
}