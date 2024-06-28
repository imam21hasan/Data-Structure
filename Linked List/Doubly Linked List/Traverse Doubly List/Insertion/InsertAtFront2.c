#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *pre;
    struct Node *next;
} *head = NULL;
typedef struct Node node;
void insertAtFront(int item)
{
    node *new = (node *)malloc(sizeof(node));
    new->pre = NULL;
    new->data = item;
    new->next = NULL;

    new->next = head;
    if (head != NULL)
    {
        head->pre = new;
    }
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
}
int main()
{
    insertAtFront(50);
    insertAtFront(40);
    insertAtFront(30);
    insertAtFront(20);

    printf("The linked list is : ");
    traverse();

    return 0;
}