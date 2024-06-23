#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;
void traverse(node *a)
{
    node *temp = a;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

void insertAtLast(node *a, int item)
{
    if (a == NULL)
    {
        printf("Overflow.");
        return;
    }
    node *temp = a;

    node *new = (node *)malloc(sizeof(node));
    new->data = item;
    new->next = NULL;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
}
int main()
{
    node *a = NULL;
    a = (node *)malloc(sizeof(node));
    node *b = (node *)malloc(sizeof(node));

    a->data = 20;
    a->next = b;
    b->data = 30;
    b->next = NULL;

    printf("The main list is : ");
    traverse(a);

    insertAtLast(a, 10);

    printf("\nThe insertion list is : ");
    traverse(a);

    return 0;
}