#include <stdio.h>
int binary(int arr[], int n, int x)
{
    int first = 0;
    int last = n - 1;

    while (first <= last)
    {
        int mid = first + (last - first) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 11;

    int result = binary(arr, n, x);

    if (result != -1)
        printf("Element found at index %d \n", result);
    else
        printf("Element not found. ");

    return 0;
}