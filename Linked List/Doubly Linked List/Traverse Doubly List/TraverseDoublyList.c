#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *pre;
    struct Node *next;
} *head = NULL;
typedef struct Node node;
void traverse()
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    head = (node *)malloc(sizeof(node));
    node *a = (node *)malloc(sizeof(node));
    node *b = (node *)malloc(sizeof(node));
    node *c = (node *)malloc(sizeof(node));

    head->pre = NULL;
    head->data = 10;
    head->next = a;

    a->pre = head;
    a->data = 20;
    a->next = b;

    b->pre = a;
    b->data = 30;
    b->next = c;

    c->pre = b;
    c->data = 40;
    c->next = NULL;

    printf("The doubly linked list is : ");
    traverse();

    return 0;
}