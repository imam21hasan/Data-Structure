#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *head;
typedef struct Node node;
void insertAtLast(int item)
{
    node *temp = head;
    node *new = (node *)malloc(sizeof(node));
    new->data = item;
    if (head == NULL)
    {
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
        temp->next=new;
    }
}
void traverse()
{
    node *temp = head;
    do
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }while (temp != head);
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