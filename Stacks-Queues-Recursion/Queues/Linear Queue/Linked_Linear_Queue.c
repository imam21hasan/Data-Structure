#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rare = NULL;
typedef struct Node node;

void enqueue(int item)
{
    node *new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("The Queue is full !!!\n");
        return;
    }
    else
    {
        new->data = item;
        new->next = NULL;
        if (rare == NULL)
        {
            front = new;
            rare = new;
        }
        else
        {
            rare->next = new;
            rare = new;
        }
    }
}
void dequeue()
{
    node *temp = front;
    if (rare == NULL)
    {
        printf("The Queue is already empty !!!\n");
        return;
    }
    int val = front->data;
    front = front->next;
    if (front == NULL)
    {
        rare = NULL;
    }
    free(temp);
    printf("Dequeue item is : %d\n", val);
}
void print()
{
    node *temp = front;
    printf("The Queue is : ");
    if (rare == NULL)
    {
        printf("Empty !!!\n");
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
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    print();
    dequeue();
    print();

    return 0;
}