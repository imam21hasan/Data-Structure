#include <stdio.h>
void tower(int n, char beg, char aux, char end)
{
    if (n == 1)
    {
        printf("Move disk 1 :  %c --> %c\n", beg, end);
    }
    else
    {
        tower(n - 1, beg, end, aux);
        printf("Move disk %d :  %c --> %c\n", n, beg, end);
        tower(n - 1, aux, beg, end);
    }
}
int main()
{
    int n;
    printf("\nEnter the number of disk : ");
    scanf("%d", &n);

    printf("\nSequence of disk transfer\n");
    tower(n, 'A', 'B', 'C');

    return 0;
}