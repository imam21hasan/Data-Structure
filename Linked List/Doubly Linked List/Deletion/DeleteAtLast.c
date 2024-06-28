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
    printf("NULL");
}
void deleteAtLast()
{
    if(head==NULL)
    {
        printf("The list is already empty!!!");
        return;
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        node *temp=head;
        node *temp2=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp2=temp->pre;
        temp2->next=NULL;
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

    deleteAtLast();
    printf("\nAfter last node deletion the linked list is : ");
    traverse();

    return 0;
}