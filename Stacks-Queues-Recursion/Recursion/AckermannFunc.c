#include <stdio.h>
int acker(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if (m > 0 && n == 0)
    {
        return acker(m - 1, 1);
    }
    else if (m > 0 && n > 0)
    {
        return acker(m - 1, acker(m, n - 1));
    }
}
int main()
{
    int m, n, rslt;
    printf("Enter the value of m & n : ");
    scanf("%d %d", &m, &n);

    rslt = acker(m, n);
    printf("The result is : %d\n", rslt);

    return 0;
}