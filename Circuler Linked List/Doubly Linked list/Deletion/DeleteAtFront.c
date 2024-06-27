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
void deleteAtFront()
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
        temp = temp->next;
    }
    head = head->next;
    temp->next = head;
    head->pre = temp;

    free(temp2);
}
int main()
{
    insert(40);
    insert(30);
    insert(20);
    insert(10);

    printf("The linked list is : ");
    traverse();

    deleteAtFront();

    printf("\nAfter delete 1st node the list is : ");
    traverse();

    return 0;
}
