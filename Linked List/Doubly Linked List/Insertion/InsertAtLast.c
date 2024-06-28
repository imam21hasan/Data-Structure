#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *pre;
    struct Node *next;
} *head = NULL;
typedef struct Node node;
void insertAtLast(int item)
{
    node *temp = head;
    node *new = (node *)malloc(sizeof(node));
    new->pre = NULL;
    new->data = item;
    new->next = NULL;

    if (head == NULL)
    {
        head = new;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->pre = temp;
    }
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
    insertAtLast(10);
    insertAtLast(20);
    insertAtLast(30);
    insertAtLast(40);

    printf("The linked list is : ");
    traverse();

    return 0;
}