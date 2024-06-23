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
    node *temp=head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void deleteAtPosition(int position)
{
    node *current = head;
    node *previous = head;

    if (head == NULL)
    {
        printf("Linked list is empty!!!");
    }
    else if (position == 1)
    {
        head = current->next;
        free(current);
    }
    else
    {
        while (position != 1)
        {
            previous = current;
            current = current->next;
            position--;
        }
        previous->next = current->next;
        free(current);
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

    deleteAtPosition(3);

    printf("\nAfter deletion the linked list is : ");
    traverse();

    return 0;
}