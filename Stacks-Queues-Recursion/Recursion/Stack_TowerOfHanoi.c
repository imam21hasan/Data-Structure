#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
struct Node
{
    int n;
    char beg;
    char aux;
    char end;
    int add;
};
typedef struct Node node;
int top = -1;
node stack[SIZE];

void push(int n, char beg, char aux, char end, int add)
{
    if (top == SIZE - 1)
    {
        printf("The stack is already full !!!\n");
        return;
    }
    else
    {
        top++;
        stack[top].n = n;
        stack[top].beg = beg;
        stack[top].aux = aux;
        stack[top].end = end;
        stack[top].add = add;
    }
}
node pop()
{
    if (top == -1)
    {
        printf("The stack is already empty !!!\n");
    }
    else
    {
        node val = stack[top];
        top--;
        return val;
    }
}
void tower(int N, char BEG, char AUX, char END)
{
    int ADD;
    push(N, BEG, AUX, END, 0);

    while (top != -1)
    {
        node rslt = pop();
        N = rslt.n;
        BEG = rslt.beg;
        AUX = rslt.aux;
        END = rslt.end;
        ADD = rslt.add;

        if (ADD == 0)
        {
            if (N == 1)
            {
                printf("Move disk 1 : %c --> %c\n", BEG, END);
            }
            else
            {
                push(N, BEG, AUX, END, 1);
                push(N - 1, BEG, END, AUX, 0);
            }
        }
        else if (ADD == 1)
        {
            printf("Move disk %d : %c --> %c\n", N, BEG, END);
            push(N, BEG, AUX, END, 2);
            push(N - 1, AUX, BEG, END, 0);
        }
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