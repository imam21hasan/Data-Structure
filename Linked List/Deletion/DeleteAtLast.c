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

void deleteAtLast()
{
    if (head == NULL)
    {
        printf("The linked list is empty!!!");
    }
    else if (head->next == NULL)
    {
        free(head);
    }
    else
    {
        node *temp1 = head;
        node *temp2 = head;
        while (temp1->next != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = NULL;
        free(temp1);
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

    deleteAtLast();

    printf("\nAfter deletion the linked list is : ");
    traverse();

    return 0;
}
