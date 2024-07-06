#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *top = NULL;
typedef struct Node node;

int isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}
void push(int item)
{
    node *new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Stack is full !!!\n");
        return;
    }
    new->data = item;
    new->next = NULL;

    new->next = top;
    top = new;
    printf("\nSuccessfully pushed item : %d\n", top->data);
}
void pop()
{
    node *temp = top;
    if (isEmpty())
    {
        printf("\nStack is already empty !!!\n");
        return;
    }
    int val = top->data;
    top = top->next;
    free(temp);
    printf("\nThe pop item is : %d\n", val);
}
void peek()
{
    if (isEmpty())
    {
        printf("\nStack is empty!!!\n");
        return;
    }
    printf("\nThe top of stack is : %d\n", top->data);
}
void print()
{
    node *temp = top;
    printf("\nThe stack is : ");
    if (isEmpty())
    {
        printf("empty !!!\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
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
            printf("\nEnter the right choice !!!\n");
        }
    }
    return 0;
}