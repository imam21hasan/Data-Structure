#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *head = NULL;
typedef struct Node node;
void insert(int item)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = item;
    new->next = head;
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
    node *pre=NULL;
    node *cur=head;
    node *next=NULL;
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=pre;

        pre=cur;
        cur=next;
    }
    head=pre;
}

int main()
{
    insert(10);
    insert(20);
    insert(30);

    printf("The main linked list is : ");
    traverse();

    reverse();

    printf("\nThe reverse linked list is : ");
    traverse();

    return 0;
}
