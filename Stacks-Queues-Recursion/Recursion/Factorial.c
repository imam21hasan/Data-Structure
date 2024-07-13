#include <stdio.h>
int fact(int f)
{
    if (f == 0)
        return 1;
    else
        return f * fact(f - 1);
}
int main()
{
    int n, rslt;
    printf("Enter the value of n : ");
    scanf("%d", &n);
    rslt = fact(n);
    printf("The foctorial of %d is : %d", n, rslt);

    return 0;
}
