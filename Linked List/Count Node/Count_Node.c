#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*head=NULL;
typedef struct Node node;
void count_Node()
{
    int count = 0;
    if (head == NULL)
    {
        printf("The linked list is empty.");
        return;
    }
    node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("The linked list contain %d nodes.", count);
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
    c->next = NULL;

    count_Node();

    return 0;
}
