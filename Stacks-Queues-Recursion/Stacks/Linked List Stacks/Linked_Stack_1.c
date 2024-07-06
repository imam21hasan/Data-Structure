#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *top = NULL;
typedef struct Node node;

void push(int item)
{
    node *new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Stack is full !!!");
        return;
    }
    new->data = item;
    new->next = NULL;

    new->next = top;
    top = new;
    printf("\nSuccessfully pushed item : %d", top->data);
}
void pop()
{
    node *temp = top;
    if (top == NULL)
    {
        printf("\nStack is empty !!!");
        return;
    }
    int val = top->data;
    top = top->next;
    free(temp);
    printf("\nThe pop item is : %d", val);
}
void peek()
{
    if (top == NULL)
    {
        printf("\nStack is empty!!!");
        return;
    }
    printf("\nThe top of stack is : %d", top->data);
}
void print()
{
    node *temp = top;
    printf("\nThe stack is : ");
    if (top == NULL)
    {
        printf("empty !!!");
        return;
    }
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    push(10);
    push(55);
    push(49);

    peek();

    print();

    pop();
    pop();

    peek();

    print();

    return 0;
}