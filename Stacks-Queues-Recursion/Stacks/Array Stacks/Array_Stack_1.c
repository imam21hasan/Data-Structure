#include <stdio.h>
#define SIZE 4
int stack[SIZE];
int top = -1;

void push(int item)
{
    if (top == SIZE - 1)
    {
        printf("\nStack is full !!!");
        return;
    }
    top++;
    stack[top] = item;
    printf("\nSuccessfully pushed item : %d", item);
}
void pop()
{
    if (top == -1)
    {
        printf("\nStack is empty !!!");
        return;
    }
    int val = stack[top];
    top--;
    printf("\nThe pop item is : %d", val);
}
void peek()
{
    if (top == -1)
    {
        printf("\nStack is empty !!!");
        return;
    }
    printf("\nThe top of stack is : %d", stack[top]);
}
void print()
{
    printf("\nThe stack is : ");
    if (top == -1)
    {
        printf("empty !!!");
        return;
    }
    for (int i = 0; i <=top; i++)
    {
        printf("%d  ", stack[i]);
    }
}
int main()
{
    push(10);
    push(20);

    print();

    peek();

    push(30);
    push(40);
    push(50);

    print();

    pop();
    pop();

    peek();

    print();

    push(60);

    print();

    pop();

    peek();

    return 0;
}