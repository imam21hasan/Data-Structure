#include <stdio.h>
int linear(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {2, 55, 7, 9, 12, 15, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 12;
    int result = linear(arr, n, target);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found ");

    return 0;
}