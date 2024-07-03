#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *pre;
    struct Node *next;
} *head = NULL;
typedef struct Node node;
void insert(int item)
{
    node *new = (node *)malloc(sizeof(node));
    new->pre = NULL;
    new->data = item;
    new->next = NULL;

    new->next = head;
    if (head != NULL)
    {
        head->pre = new;
    }
    head = new;
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
void reverse()
{
    node *temp = NULL;
    node *cur = head;
    while (cur != NULL)
    {
        temp = cur->pre;

        cur->pre = cur->next;
        cur->next = temp;

        cur = cur->pre;
    }
    if (temp != NULL)
    {
        head = temp->pre;
    }
}
int main()
{
    insert(40);
    insert(30);
    insert(20);
    insert(10);

    printf("The main list is : ");
    traverse();

    reverse();

    printf("\nThe reverse list is : ");
    traverse();

    return 0;
}
