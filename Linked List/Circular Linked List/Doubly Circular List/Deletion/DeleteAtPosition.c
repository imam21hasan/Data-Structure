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
void deleteAtPosition(int pos)
{
    node *temp = head;
    node *temp2 = head;

    if (pos == 1)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        head = head->next;
        temp->next = head;
        head->pre = temp;

        free(temp2);
    }
    while (pos != 1)
    {
        temp2 = temp;
        temp = temp->next;
        pos--;
    }
    if (temp->next == head)
    {
        temp2->next = head;
        head->pre = temp2;
    }
    else
    {
        temp2->next = temp->next;
        temp->next->pre = temp2;

        free(temp);
    }
}
int main()
{
    insert(40);
    insert(30);
    insert(20);
    insert(10);

    printf("The linked list is : ");
    traverse();

    int n;
    printf("\nEnter the position : ");
    scanf("%d", &n);

    deleteAtPosition(n);

    printf("After delete %dth node the list is : ", n);
    traverse();

    return 0;
}