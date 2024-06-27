#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
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
        temp->next = new;
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
        temp->next = new;

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
            temp->next=new;
        }
        else
        {
            new->next = temp->next;
            temp->next=new;
        }
    }
}
int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    printf("The main linked list is : ");
    traverse();

    int n;
    printf("\nEnter the position : ");
    scanf("%d", &n);

    insertAtPosition(n, 77);

    printf("After insert at %dth position the list is : ", n);
    traverse();

    return 0;
}