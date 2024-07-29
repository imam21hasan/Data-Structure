#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *pre;
    struct Node *next;
} *head=NULL;
typedef struct Node node;
void insertAtFront(int item)
{
    node *temp = head;
    node *new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Overflow !!!\n");
        return;
    }
    new->data = item;
    if (head == NULL)
    {
        new->pre = new;
        new->next = new;

        head = new;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        new->next = head;
        new->pre = temp;
        head->pre = new;
        temp->next = new;

        head = new;
    }
}
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
    insertAtFront(40);
    insertAtFront(30);
    insertAtFront(20);
    insertAtFront(10);

    printf("The linked list is : ");
    traverse();

    return 0;
}
