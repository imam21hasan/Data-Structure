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
void insertAtPosition(int pos, int item)
{
    node *temp = head;
    node *new = (node *)malloc(sizeof(node));
    new->data = item;

    if (pos == 1)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        new->next = head;
        head->pre = new;
        temp->next = new;
        new->pre = temp;

        head = new;
    }
    else
    {
        int i = 1;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next == head)
        {
            new->next = head;
            new->pre = temp;
            temp->next = new;
            head->pre = new;
        }
        else
        {
            new->next = temp->next;
            new->pre = temp;
            temp->next = new;
            temp->next->pre = new;
        }
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

    insertAtPosition(n, 77);

    printf("After insert at %dth position the list is : ", n);
    traverse();
    return 0;
}