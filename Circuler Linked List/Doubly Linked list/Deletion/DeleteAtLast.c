#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *pre;
    struct Node *next;
} *head;
typedef struct Node node;
void insert(int item)
{
    node *temp = head;
    node *new = (node *)malloc(sizeof(node));
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
void deleteAtLast()
{
    node *temp = head;
    node *temp2 = head;
    if (head == NULL)
    {
        printf("The list is already empty!!!");
        return;
    }
    else if (temp->next == head)
    {
        head = NULL;
        free(temp);
    }
    while (temp->next != head)
    {
        temp2=temp;
        temp = temp->next;
    }
    temp2->next=head;
    head->pre=temp2;

    free(temp);
}
int main()
{
    insert(40);
    insert(30);
    insert(20);
    insert(10);

    printf("The linked list is : ");
    traverse();

    deleteAtLast();

    printf("\nAfter delete last node the list is : ");
    traverse();

    return 0;
}