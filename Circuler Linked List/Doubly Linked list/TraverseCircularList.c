#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *head;
typedef struct Node node;

void traverse()
{
    node *temp = head;
    do
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
}
int main()
{
    head = (node *)malloc(sizeof(node));
    node *a = (node *)malloc(sizeof(node));
    node *b = (node *)malloc(sizeof(node));
    node *c = (node *)malloc(sizeof(node));

    head->data = 10;
    head->next = a;

    a->data = 20;
    a->next = b;

    b->data = 30;
    b->next = c;

    c->data = 40;
    c->next = head;

    printf("The linked list is : ");
    traverse();
}