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

int main()
{
    node *a = (node *)malloc(sizeof(node));
    node *b = (node *)malloc(sizeof(node));
    node *c = (node *)malloc(sizeof(node));

    a->data = 5;
    a->next = b;

    b->data = 10;
    b->next = c;

    c->data = 15;
    c->next = NULL;

    printf("The linked list is : ");
    traverse(a);

    return 0;
}
