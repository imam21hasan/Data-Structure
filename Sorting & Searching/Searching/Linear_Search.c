#include <stdio.h>
int linearSearch(int arr[], int n, int target)
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
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 12;

    int result = linearSearch(arr, n, target);

    if (result != -1)
    {
        printf("%d is found at index %d.", target, result);
    }
    else
    {
        printf("%d is not found !!!", target);
    }

    return 0;
}