#include <stdio.h>
int fibo(int f)
{
    if (f <= 0)
        return 0;
    else if (f == 1)
        return 1;
    else
        return fibo(f - 2) + fibo(f - 1);
}
int main()
{
    int n, rslt;
    printf("Enter the value of n : ");
    scanf("%d", &n);

    rslt = fibo(n);
    printf("The %dth fibonacci sequence is : %d", n, rslt);

    return 0;
}