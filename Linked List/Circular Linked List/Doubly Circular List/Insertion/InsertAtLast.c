#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *pre;
    struct Node *next;
} *head=NULL;
typedef struct Node node;
void insertAtLast(int item)
{
    node *new = (node *)malloc(sizeof(node));
    if(new==NULL)
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
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        new->next = head;
        new->pre = temp;
        temp->next = new;
        head->pre = new;
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
    insertAtLast(55);
    insertAtLast(65);
    insertAtLast(75);
    insertAtLast(85);

    printf("The linked list is : ");
    traverse();

    return 0;
}
