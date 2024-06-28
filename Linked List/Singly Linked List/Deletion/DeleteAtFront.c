#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;
typedef struct Node node;

void insert(int item)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = item;
    new->next = head;
    head = new;
}
void traverse()
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("NULL.  ");
}

void deleteAtFront()
{
    if (head == NULL)
    {
        printf("The main linked is Empty!!!");
    }
    
    else
    {
        node *temp = head;
        head = head->next;
        free(temp);
    }
}
int main()
{
    insert(50);
    insert(40);
    insert(30);
    insert(20);
    insert(10);

    printf("The main linked list is : ");
    traverse();

    deleteAtFront();

    printf("\nAfter deletion the linked list is : ");
    traverse();

    return 0;
}
