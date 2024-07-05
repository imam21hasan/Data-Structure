#include <stdio.h>
#define SIZE 4
int stack[SIZE];
int top = -1;

int isFull()
{
    if (top == SIZE - 1)
    {
        return 1;
    }
    return 0;
}
int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}
void push(int item)
{
    if (isFull())
    {
        printf("\nStack is full !!!\n");
        return;
    }
    top++;
    stack[top] = item;
    printf("\nSuccessfully pushed item : %d\n", item);
}
void pop()
{
    if (isEmpty())
    {
        printf("\nStack is empty !!!\n");
        return;
    }
    int val = stack[top];
    top--;
    printf("\nThe pop item is : %d\n", val);
}
void peek()
{
    if (isEmpty())
    {
        printf("\nStack is empty !!!\n");
        return;
    }
    printf("\nThe top of stack is : %d\n", stack[top]);
}
void print()
{
    printf("\nThe stack is : ");
    if (isEmpty())
    {
        printf("empty !!!\n");
        return;
    }
    for (int i = 0; i <= top; i++)
    {
        printf("%d  ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int n, item;
    while (1)
    {
        printf("\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.print\n");
        printf("5.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Enter the pushed item : ");
            scanf("%d", &item);
            push(item);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            print();
            break;

        case 5:
            return 0;

        default:
            printf("\nEnter the right choice !!!");
        }
    }
    return 0;
}