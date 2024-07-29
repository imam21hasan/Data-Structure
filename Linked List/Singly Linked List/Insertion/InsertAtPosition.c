#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *a = NULL;
typedef struct Node node;

void traverse()
{
    node *temp = a;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

void insertAtPosition(int item, int pos)
{
    node *temp = a;
    node *new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Overflow.");
        return;
    }
    new->data = item;
    new->next = NULL;

    if (pos == 1)
    {
        new->next = a;
        a = new;
        return;
    }
    int i = 1;
    while (i < pos - 1)
    {
        if (temp == NULL || temp->next == NULL)
        {
            printf("Item position not found in the linked list !!!\n");
            return;
        }
        temp = temp->next;
        i++;
    }
    new->next = temp->next;
    temp->next = new;
}
int main()
{
    a = (node *)malloc(sizeof(node));
    node *b = (node *)malloc(sizeof(node));

    a->data = 20;
    a->next = b;
    b->data = 30;
    b->next = NULL;

    printf("The main list is : ");
    traverse();

    int n;
    printf("\nEnter the position : ");
    scanf("%d", &n);

    insertAtPosition(40, n);

    printf("The inserted list is : ");
    traverse();

    return 0;
}
