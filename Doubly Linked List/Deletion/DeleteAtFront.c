#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *pre;
    struct Node *next;
}*head=NULL;
typedef struct Node node;
void insert(int item)
{
    node *new=(node *)malloc(sizeof(node));
    new->next=NULL;
    new->data=item;
    new->next=NULL;

    new->next=head;
    if(head!=NULL)
    {
        head->pre=new;
    }
    head=new;
}
void traverse()
{
    node *temp=head;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("NULL.");
}
void deleteAtFront()
{
    node *temp=head;
    if(head==NULL)
    {
        printf("List is already empty!!!");
        return;
    }
    head=head->next;
    head->pre=NULL;
    free(temp);
}
int main()
{
    insert(40);
    insert(30);
    insert(20);
    insert(10);

    printf("The main linked list is : ");
    traverse();

    deleteAtFront();
    printf("\nAfter 1st node deletion the linked list is : ");
    traverse();

    return 0;
}
