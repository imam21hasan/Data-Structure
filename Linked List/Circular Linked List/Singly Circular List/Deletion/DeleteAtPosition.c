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
        temp->next = head->next;
        head = head->next;
        free(temp2);
    }
    else
    {
        while (pos != 1)
        {
            temp2 = temp;
            temp = temp->next;
            pos--;
        }
        temp2->next = temp->next;
        free(temp);
    }
}
int main()
{
    insert(40);
    insert(30);
    insert(20);
    insert(10);

    printf("The main linked list is : ");
    traverse();

    int n;
    printf("\nEnter the position : ");
    scanf("%d", &n);

    deleteAtPosition(n);

    printf("After delete %dth node the list is : ", n);
    traverse();

    return 0;
}