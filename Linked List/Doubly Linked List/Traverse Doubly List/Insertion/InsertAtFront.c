#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *pre;
    struct Node *next;
} *head = NULL;
typedef struct Node node;
void insertEmptyList(int item)
{
    node *new = (node *)malloc(sizeof(node));
    new->pre = NULL;
    new->data = item;
    new->next = NULL;
    head = new;
}
void insertAtFront(int item)
{
    node *new = (node *)malloc(sizeof(node));
    new->pre = NULL;
    new->data = item;
    new->next = NULL;
    
    new->next = head;
    head->pre=new;
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
int main()
{
    insertEmptyList(10);

    insertAtFront(21);
    insertAtFront(28);
    insertAtFront(35);

    printf("The linked list is : ");
    traverse();

    return 0;
}
